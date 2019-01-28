package main

import (
	"encoding/hex"
	"fmt"
	"log"
	"os"

	"github.com/spf13/cobra"
)

func main() {
	var rootCmd = &cobra.Command{Use: os.Args[0]}
	var password string
	var settingsKey string
	var verbose bool

	var cmdInspect = &cobra.Command{
		Use:   "inspect [tdata file]",
		Short: "inspect tdata file",
		Args:  cobra.ExactArgs(1),
		Run: func(cmd *cobra.Command, args []string) {
			filename := args[0]
			f, err := os.Open(filename)
			if err != nil {
				log.Fatalf("could not open file '%s': %v", filename, err)
			}
			defer f.Close()
			PrintTdataFile(f, verbose)
		},
	}
	cmdInspect.Flags().BoolVarP(&verbose, "verbose", "v", false, "show content of streams")
	rootCmd.AddCommand(cmdInspect)

	cmdSettings := &cobra.Command{
		Use:   "settings [settings file]",
		Short: "show settings file properties",
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
				log.Fatalf("could not open file '%s': %v", filename, err)
			}
			defer f.Close()
			settings, err := ReadTdataSettings(f)
			if err != nil {
				log.Fatalf("could not interpret settings file: %v", err)
			}
			settingsKey, err := getSettingsKey(settings, password)
			if err != nil {
				log.Fatalf("could not extract settings key: %v", err)
			}
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
				log.Fatalf("could not open file '%s': %v", filename, err)
			}
			defer f.Close()
			settings, err := ReadTdataSettings(f)
			if err != nil {
				log.Fatalf("could not interpret settings file: %v", err)
			}
			settingsKey, err := getSettingsKey(settings, password)
			if err != nil {
				log.Fatalf("could not extract settings key: %v", err)
			}
			decrypted, err := decryptSettings(settings, settingsKey)
			if err != nil {
				log.Fatalf("could not decrypt settings file: %v", err)
			}
			fmt.Println(hex.EncodeToString(decrypted))
		},
	}
	cmdSettingsDecrypt.Flags().StringVarP(&password, "password", "p", "", "optional password (default='')")
	cmdSettings.AddCommand(cmdSettingsDecrypt)

	cmdMap := &cobra.Command{
		Use:   "map [map file]",
		Short: "work with map file",
	}
	rootCmd.AddCommand(cmdMap)
	cmdMapDecrypt := &cobra.Command{
		Use:   "decrypt [map file]",
		Short: "decrypt map file",
		Run: func(cmd *cobra.Command, args []string) {

		},
	}
	cmdMapDecrypt.Flags().StringVarP(&settingsKey, "settingsKey", "s", "", "settings key in hex")
	cmdMap.AddCommand(cmdMapDecrypt)

	rootCmd.Execute()
}