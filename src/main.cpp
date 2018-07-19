/*
 ============================================================================
 Name        : testtest.c
 Author      : Anes Dzemic
 Version     :
 Copyright   : test purpose only
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>
#include "common/Dir.hpp"

using namespace std;
//const char usage[] = "here is all ok";

const char usage[] = {
    #include "common/hello_world.use.hpp"
};

void show_all (int n){
	//vector <string> f = get_files("/home/andz8891"); //core dump
	vector <string> f = get_files(".");
	for (int counter = 1; counter <=n; ++counter){
		cout << counter << " : " << f.size() << endl;
	}
	for (string &s : f) {
	    cout << s << endl;
	}
	//show_env();
}

int main(int argc, char *argv[]) {







	printf("%s\n", usage);
	int i = 0;
	int option = -1;
	int repeats = 1;
	char *title = NULL;

	while((option = getopt(argc, argv, "n:h")) != -1) {
		switch(option) {
			case 'n':
				repeats = atoi(optarg);
				break;
			case 'h':
				printf("%s", usage);
				return EXIT_FAILURE;
				break;
			default:
				printf("%s", usage);
				return EXIT_FAILURE;
				break;
		}
	}

	if (optind < argc) { title = argv[optind]; }

	for (i = 0; i < repeats; i++) { printf ("%s\n", title ? title : HELLO_WORLD_DEFAULT); }
	show_all(repeats);
	return EXIT_SUCCESS;
}
