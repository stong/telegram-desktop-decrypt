/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
// #include "core/launcher.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

#include "storage/cache/storage_cache_types.h"
#include "storage/cache/storage_cache_database.h"
#include "storage/storage_encryption.h"
#include "storage/storage_encrypted_file.h"
#include "base/openssl_help.h"
#include "base/bytes.h"


#include <string>
#include "base/basic_types.h"
#include <QtCore/QString>

void Decrypt(const char* filename) {
	bytes::vector fuck;
	{
		// put the bytes to your key (from `telegram-desktop-decrypt key getkey`) here
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
		fuck.push_back((gsl::byte)0x00);
	}

	// Storage::Cache::details::Settings settings;
	// Storage::Cache::Database db("C:\\Users\\User\\Documents\\telegram-desktop-decrypt\\work\\tdata\\user_data\\cache", settings);

	fuck.resize(Storage::EncryptionKey::kSize);
	auto key = Storage::EncryptionKey(std::move(fuck));
	// db.open();

	Storage::File f;
	auto result = f.open(filename, Storage::File::Mode::Read, key);
	printf("result = %d\n", result);

	auto size = f.size();
	printf("Size = %lld\n", size);

	bytes::vector data;
	data.resize(size);

	f.read(data);

	// for (int64 i = 0; i < size; i++) {
	// 	printf("%02x ", data[i]);
	// }

	auto lol = std::string(filename) + ".dec";
	puts(lol.c_str());
	FILE* fucker = fopen(lol.c_str(), "wb");
	for (size_t written = 0; written < size; written += fwrite(data.data()+written, 1, size-written, fucker));
	fclose(fucker);

	puts("");
}

int main(int argc, char *argv[]) {
	// AllocConsole();
	// FILE *file = nullptr;
	// freopen_s(&file,"CONIN$", "r", stdin);
	// freopen_s(&file, "CONOUT$", "w", stdout);
    // setvbuf(stdout, NULL, _IONBF, 0 );
    // setvbuf(stderr, NULL, _IONBF, 0 );
	// printf("Hello world\n");

	// Decrypt("C:\\Users\\User\\Documents\\telegram-desktop-decrypt\\work\\tdata\\user_data\\cache\\0\\00\\FDDC933F4E58");
	if (argc < 2) abort();
	Decrypt(argv[1]);

	// system("pause");
	// const auto launcher = Core::Launcher::Create(argc, argv);
	// return launcher ? launcher->exec() : 1;
}

