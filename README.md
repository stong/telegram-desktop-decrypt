# telegram-desktop-decrypt
Tool to decrypt tdata files.

Telegram Desktop (the one that runs on desktops, not on phones) has a "tdata" folder where it stores some encrypted files.
This folder is normally found at "~/.local/share/TelegramDesktop" on Linux 
and at "%USERPROFILE%\AppData\Roaming\Telegram Desktop" on Windows.

This tool can decrypt those files, which contains settings and cache files, but not chat histories because these are not included in tdata.

## Usage

```
./telegram-desktop-decrypt decrypt tdata/keys_data tdata/D877F783D5D3EF8C/1234567890ABCD -s 0 -o outfile
./telegram-desktop-decrypt map listkeys tdata/keys_data tdata/D877F783D5D3EF8C/maps -s 0 -o outfile
./telegram-desktop-decrypt key getkey tdata/keys_data
```

