// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "TreeType.h"
#include "champion.h"

void main()
{
	TreeType<Champion> myTree;
	
	Champion obj1("alpah", 1, 2);
	Champion obj2("alpah", 1, 2);

	myTree.InsertItem(obj1);

	std::fstream fs;
	fs.open("test.txt", std::fstream::in | std::fstream::out | std::fstream::app);

	Champion tempObj;
	bool finished = false;

	myTree.ResetTree(POST_ORDER);

	myTree.InsertItem(obj1);

	myTree.GetNextItem(tempObj, POST_ORDER, finished);
	while (!finished)
	{
		std::cout << tempObj;
		myTree.GetNextItem(tempObj, POST_ORDER, finished);
	}

	myTree.PrintTree(fs);

	std::cout << std::endl << "Hit any key to contine...\n";
	std::cin.get();

	return;
}