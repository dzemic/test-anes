/*
 * Dir.cpp
 *
 *  Created on: Jul 16, 2018
 *      Author: andz8891
 */
#include <stdio.h>
#include <dirent.h>

#include <iostream>
#include <string>
#include <vector>
#include <Dir.hpp>

#include <stdlib.h>
#include <sys/stat.h>
using namespace std;

char buf[PATH_MAX + 1];


vector <string> get_files(const char *d){
	vector <string> files;
	if (auto dir = opendir(d)) {
			while (auto f = readdir(dir)) {
				if (!f->d_name || f->d_name[0] == '.')
					continue; // Skip everything that starts with a dot
				//printf("File: %s\n", f->d_name);
				//cout << realpath(f->d_name, buf);
				files.push_back(realpath(f->d_name, buf));
			}
			closedir(dir);
	}
	return files;
}


void show_env(void){
	extern char *environ[];
    int index = 0;
    char **env = (char **)environ[0];
    printf("Environment variables:\n");
    index = 0;
    while (env[index])
    {
        printf("envp[%d]: %s\n", index, env[index]);
        ++index;
    }
}


