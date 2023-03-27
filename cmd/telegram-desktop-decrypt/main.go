package main

import (
	"encoding/hex"
	"encoding/json"
	"fmt"
	"github.com/atilaromero/telegram-desktop-decrypt/qt"
	"github.com/atilaromero/telegram-desktop-decrypt/tdata/decrypted"
	"github.com/atilaromero/telegram-desktop-decrypt/tdata/encrypted"
	"log"
	"os"
	"reflect"

	"github.com/atilaromero/telegram-desktop-decrypt/decrypt"
	"github.com/atilaromero/telegram-desktop-decrypt/tdata"

	"github.com/spf13/cobra"
)

func main() {
	var rootCmd = &cobra.Command{Use: os.Args[0]}
	var password string
	var output string
	var verbose bool
	var stream int
	var parse bool

	var cmdInspect = &cobra.Command{
		Use:   "inspect [tdata file]",
		Short: "inspect tdata file",
		Args:  cobra.ExactArgs(1),
		Run: func(cmd *cobra.Command, args []string) {
			filename := args[0]
			f, err := os.Open(filename)
			if err != nil {
				log.Fatalf("could not open file '%s': %+v", filename, err)
			}
			defer f.Close()
			rawtdf, err := tdata.ReadRawTDF(f)
			if err != nil {
				log.Fatalf("%+v", err)
			}
			rawtdf.Print(verbose)
		},
	}
	cmdInspect.Flags().BoolVarP(&verbose, "verbose", "v", false, "show content of streams")
	rootCmd.AddCommand(cmdInspect)

	cmdSettings := &cobra.Command{
		Use:   "settings [settings file]",
		Short: "work with settings file",
	}
	rootCmd.AddCommand(cmdSettings)
	cmdSettingsKey := &cobra.Command{
		Use:   "getkey [settings file]",
		Short: "get settings key in hex",
		Args:  cobra.ExactArgs(1),
		Run: func(cmd *cobra.Command, args []string) {
			filename := args[0]
			f, err := os.Open(filename)
			if err != nil {
				log.Fatalf("could not open file '%s': %+v", filename, err)
			}
			defer f.Close()
			rawtdf, err := tdata.ReadRawTDF(f)
			if err != nil {
				log.Fatalf("%+v", err)
			}
			settings, err := encrypted.ReadESettings(rawtdf)
			if err != nil {
				log.Fatalf("could not interpret settings file: %+v", err)
			}
			settingsKey := settings.GetKey(password)
			fmt.Println(hex.EncodeToString(settingsKey))
		},
	}
	cmdSettingsKey.Flags().StringVarP(&password, "password", "p", "", "optional password (default='')")
	cmdSettings.AddCommand(cmdSettingsKey)
	cmdSettingsDecrypt := &cobra.Command{
		Use:   "decrypt [settings file]",
		Short: "decrypt settings file",
		Args:  cobra.ExactArgs(1),
		Run: func(cmd *cobra.Command, args []string) {
			filename := args[0]
			f, err := os.Open(filename)
			if err != nil {
				log.Fatalf("could not open file '%s': %+v", filename, err)
			}
			defer f.Close()
			rawtdf, err := tdata.ReadRawTDF(f)
			if err != nil {
				log.Fatalf("%+v", err)
			}
			settings, err := encrypted.ReadESettings(rawtdf)
			if err != nil {
				log.Fatalf("could not interpret settings file: %+v", err)
			}
			settingsKey := settings.GetKey(password)
			plain, err := settings.Decrypt(settingsKey)
			if err != nil {
				log.Fatalf("could not interpret settings file: %+v", err)
			}
			if !parse {
				os.Stdout.Write(plain)
				return
			}
			parsed, err := decrypted.ParseCache(plain, decrypted.ReverseLSK(decrypted.UserSettings{}))
			if err != nil {
				log.Fatalf("could not interpret settings file: %+v", err)
			}
			m, err := json.Marshal(parsed)
			if err != nil {
				log.Fatalf("could not interpret settings file: %+v", err)
			}
			os.Stdout.Write(m)
		},
	}
	cmdSettingsDecrypt.Flags().StringVarP(&password, "password", "p", "", "optional password (default='')")
	cmdSettingsDecrypt.Flags().BoolVarP(&parse, "parse", "", true, "(default=true)")
	cmdSettings.AddCommand(cmdSettingsDecrypt)

	cmdKey := &cobra.Command{
		Use:   "key [key file]",
		Short: "work with key file",
	}
	rootCmd.AddCommand(cmdKey)
	cmdKeyGetkey := &cobra.Command{
		Use:   "getkey [map file]",
		Short: "get map key in hex",
		Args:  cobra.ExactArgs(1),
		Run: func(cmd *cobra.Command, args []string) {
			filename := args[0]
			f, err := os.Open(filename)
			if err != nil {
				log.Fatalf("could not open file '%s': %+v", filename, err)
			}
			defer f.Close()
			rawtdf, err := tdata.ReadRawTDF(f)
			if err != nil {
				log.Fatalf("could not interpret file '%s': %+v", filename, err)
			}
			emap, err := encrypted.ReadEMap(rawtdf)
			if err != nil {
				log.Fatalf("could not interpret map file: %+v", err)
			}
			localkey, err := emap.GetKey(password)
			if err != nil {
				log.Fatalf("could not decrypt map file: %+v", err)
			}
			fmt.Println(hex.EncodeToString(localkey))
		},
	}
	cmdKeyGetkey.Flags().StringVarP(&password, "password", "p", "", "optional password (default='')")
	cmdKey.AddCommand(cmdKeyGetkey)

	cmdMap := &cobra.Command{
		Use:   "map [key file] [map file]",
		Short: "work with map file",
	}
	rootCmd.AddCommand(cmdMap)

	cmdMapListKeys := &cobra.Command{
		Use:   "listkeys [key file] [map file]",
		Short: "decrypt map and list keys found on it",
		Run: func(cmd *cobra.Command, args []string) {
			filename := args[0]
			f, err := os.Open(filename)
			if err != nil {
				log.Fatalf("could not open file '%s': %+v", filename, err)
			}
			defer f.Close()
			rawtdf, err := tdata.ReadRawTDF(f)
			if err != nil {
				log.Fatalf("could not interpret file '%s': %+v", filename, err)
			}
			emap, err := encrypted.ReadEMap(rawtdf)
			if err != nil {
				log.Fatalf("%+v", err)
			}
			localkey, err := emap.GetKey(password)
			if err != nil {
				log.Fatalf("%+v", err)
			}

			filename = args[1]
			f2, err := os.Open(filename)
			if err != nil {
				log.Fatalf("could not open file '%s': %+v", filename, err)
			}
			defer f2.Close()

			rawtdf2, err := tdata.ReadRawTDF(f2)
			if err != nil {
				log.Fatalf("could not interpret file '%s': %+v", filename, err)
			}
			streams, err := qt.ReadStreams(rawtdf2.Data)
			if err != nil {
				log.Fatalf("could not interpret qt streams '%s': %+v", filename, err)
			}
			data, err := decrypt.DecryptLocal(streams[2], localkey)
			if err != nil {
				log.Fatalf("failed to decrypt '%s': %+v", filename, err)
			}
			dmap, err := decrypted.ReadDMap(data)
			if err != nil {
				log.Fatalf("%+v", err)
			}
			for k, v := range dmap.Files {
				fmt.Println(k, reflect.TypeOf(decrypted.LSK[v]))
			}
		},
	}
	cmdMapListKeys.Flags().StringVarP(&password, "password", "p", "", "optional password (default='')")
	cmdMap.AddCommand(cmdMapListKeys)

	cmdDecrypt := &cobra.Command{
		Use:   "decrypt [key file] [map file]",
		Short: "decrypt a regular tdata file",
		Run: func(cmd *cobra.Command, args []string) {
			filename := args[0]
			f, err := os.Open(filename)
			if err != nil {
				log.Fatalf("could not open file '%s': %+v", filename, err)
			}
			defer f.Close()
			rawtdf, err := tdata.ReadRawTDF(f)
			if err != nil {
				log.Fatalf("could not interpret file '%s': %+v", filename, err)
			}
			emap, err := encrypted.ReadEMap(rawtdf)
			if err != nil {
				log.Fatalf("%+v", err)
			}
			localkey, err := emap.GetKey(password)
			if err != nil {
				log.Fatalf("%+v", err)
			}
			// settings, err := encrypted.ReadESettings(rawtdf)
			// localkey := settings.GetKey("")

			filename = args[1]
			f2, err := os.Open(filename)
			if err != nil {
				log.Fatalf("could not open file '%s': %+v", filename, err)
			}
			defer f2.Close()

			rawtdf2, err := tdata.ReadRawTDF(f2)
			if err != nil {
				log.Fatalf("could not interpret file '%s': %+v", filename, err)
			}
			streams, err := qt.ReadStreams(rawtdf2.Data)
			if err != nil {
				log.Fatalf("could not interpret qt streams '%s': %+v", filename, err)
			}
			data, err := decrypt.DecryptLocal(streams[stream], localkey)
			if err != nil {
				log.Fatalf("failed to decrypt '%s': %+v", filename, err)
			}

			if output != "" {
				f, err := os.Create(output)
				if err != nil {
					log.Fatalf("could not create file '%s': %+v", output, err)
				}
				defer f.Close()
				f.Write(data)
			} else {
				os.Stdout.Write(data)
			}
		},
	}
	cmdDecrypt.Flags().StringVarP(&output, "outfile", "o", "", "output file")
	cmdDecrypt.Flags().IntVarP(&stream, "stream", "s", 0, "stream number (default=0)")
	rootCmd.AddCommand(cmdDecrypt)

	rootCmd.Execute()
}
