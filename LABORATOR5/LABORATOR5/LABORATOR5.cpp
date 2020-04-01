#include <iostream>
#include "Tests.h"
#include "Service.h"
#include "UI.h"
using namespace std;

int main()
{
	tests();
	bool k = true;
	Service s; UI ui;
	ui.printMenu();
	char a[5] = "git1"; char b[5] = "git2"; char c[5] = "git3";
	Project p(a, 2, 0); Project p1(b, 10, 5); Project p2(c, 8, 2);
	s.addProject(p); s.addProject(p1); s.addProject(p2);
	while (k)
	{
		int option = 0;
		cout << "Introduceti optiunea dorita: ";
		cin >> option;
		if (option == 1)
		{
			ui.addProject(s);
			ui.printMenu();
			continue;
		}
		if (option == 2)
		{
			ui.getAll(s);
			ui.printMenu();
			continue;
		}
		if (option == 3)
		{
			ui.updateProject(s);
			ui.getAll(s);
			ui.printMenu();
			continue;
		}
		if (option == 4)
		{
			ui.delProject(s);
			ui.getAll(s);
			ui.printMenu();
			continue;
		}
		if (option == 5)
		{
			ui.filterProjects(s);
			ui.printMenu();
			continue;
		}
		if (option == 6)
		{
			ui.delProjects(s);
			ui.getAll(s);
			ui.printMenu();
			continue;
		}
		if (option == 7)
			k = false;
	}
}

