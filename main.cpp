#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <vector>
#include "stock.h"

std::vector<SDT> StockDataArray;

int main(int argc, char** argv) {
	const char* filename = NULL;
	const char* ofn = "output.txt";
	if (argc >= 2) {
		filename = argv[1];
	} else {
		std::cout<<"must input the stock data file!!";
		exit (1);
	}
	FILE* fp = fopen(filename, "r");
	StockDataType d;
	FILE* ofp = fopen(ofn, "w+");
	if (!fp || !ofp) {
		std::cout<<"cannot open file for read/write, just return;"<<std::endl;
		exit (1);
	}
	
	int index =0;
	while (9) {
		memset(&d, sizeof(StockDataType), 0);
		int count = fread(&d, 1, sizeof(d), fp);
		std::cout<<"read "<<index<<"th times"<<std::endl;
		++index;
		
		if (count != sizeof(d)){
			std::cout<<"file read return "<<count<<", just return\n";
			break;
		}
		
		SDT a(d);
		//std::cout<<a.toString()<<std::endl;
		StockDataArray.push_back(a);
	}
	fclose (fp);
	std::vector<SDT>::iterator it = StockDataArray.begin();
	std::vector<SDT>::iterator end = StockDataArray.end();
	for(; it != end; ++it) {
		std::cout<<it->toString();
		fprintf(ofp, "%s\n", it->toString().c_str());
	}
	//std::cout<<a.toString();
	return 0;
}

