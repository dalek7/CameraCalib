#pragma once
#include <stdarg.h>  // For va_start, etc.
#include <memory>    // For std::unique_ptr
#include <string>
#include <vector>
#include <algorithm> //for sort
using namespace std;


#include <windows.h>
#include <direct.h>

#ifdef WINDOWS

#endif

#ifdef __linux__
//linux code goes here
#include <unistd.h>
#elifdef WINDOWS
// windows code goes here
#include <windows.h>
#include <direct.h>
#else

#endif

// http://stackoverflow.com/a/7430262
inline void MakeSurePathExists(std::string dir_name)//, mode_t mode = 0755
{
	struct stat st = { 0 };

	if (stat(dir_name.c_str(), &st) == -1)
	{
		//cout << "Creating..." << dir_name << "... ";
#ifdef WINDOWS
		if (_mkdir(dir_name.c_str()) == 0)
			cout << "Directory " << dir_name << "was successfully created\n";
		else
			cout << "Problem removing directory.." << dir_name << endl;
		
#else
		mkdir(dir_name.c_str(), mode); //linux
#endif
	}
	else
	{
		std::cout << "Directory " << dir_name << " already exists !" << std::endl;
	}
}




#include <sys/stat.h>
#include <stdio.h>

#ifdef __linux__
#include <dirent.h>
#endif

// Returns a list of files in a directory (except the ones that begin with a dot)
// http://stackoverflow.com/a/1932861

inline void GetFilesInDirectory(std::vector<string> &out, const std::string &directory)
{

	//std::cout << directory.c_str() << std::endl;


#ifdef __linux__

	DIR *dir;
	class dirent *ent;
	class stat st;

	dir = opendir(directory.c_str());


	while ((ent = readdir(dir)) != NULL) {
		const string file_name = ent->d_name;
		const string full_file_name = directory + "/" + file_name;

		if (file_name[0] == '.')
			continue;

		if (stat(full_file_name.c_str(), &st) == -1)
			continue;

		const bool is_directory = (st.st_mode & S_IFDIR) != 0;

		if (is_directory)
			continue;

		out.push_back(full_file_name);
	}

	closedir(dir);

	std::sort(out.begin(), out.end());
#else
	HANDLE dir;
	WIN32_FIND_DATA file_data;
	if ((dir = FindFirstFile((directory + "/*").c_str(), &file_data)) == INVALID_HANDLE_VALUE)
		return; /* No files found */

	do {
		const string file_name = file_data.cFileName;
		const string full_file_name = directory + "/" + file_name;
		const bool is_directory = (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;

		if (file_name[0] == '.')
			continue;

		if (is_directory)
			continue;

		out.push_back(full_file_name);
	} while (FindNextFile(dir, &file_data));

	FindClose(dir);

#endif
} // GetFilesInDirectory

inline static
int GetFilesofExtInDirectory(std::vector<std::string> &out, const string &directory, const string &_extension)
{
	std::vector<std::string> fns;
	GetFilesInDirectory(fns, directory);
	std::vector<std::string> fn1;
	for (std::vector<string>::iterator it = fns.begin(); it != fns.end(); ++it)
	{
		vector<string> tokens;
		Tokenize(*it, tokens, ".");
		string ext = tokens[tokens.size() - 1];

		if (IsEqualStrings(ext, _extension))
		{
			fn1.push_back(*it);

		}
	}
	out = fn1;

	std::sort(out.begin(), out.end());

	return fn1.size();
}

