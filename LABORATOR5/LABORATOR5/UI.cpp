#include "UI.h"
#include <iostream>
using namespace std;

//constructor
UI::UI()
{
	this->s;
}

//destructor
UI::~UI()
{
}

//afisare meniu
void UI::printMenu()
{
	cout << "1. Adaugare proiect." << endl;
	cout << "2. Afisare proiecte" << endl;
	cout << "3. Update proiect " << endl;
	cout << "4. Stergere proiect" << endl;
	cout << "5. Afisare exercitii care au cel putin K branch-uri si L commit-uri" << endl;
	cout << "6. Eliminare exercitii care au noOfBranches*totalNoOfCommits = 0" << endl;
	cout << "7. Iesire." << endl;
}

//adaugare element de tip Project
void UI::addProject(Service& s)
{
	char gitPath[100];
	int noOfBranches, totalNoOfCommits;  int n = 0;
	cout << "Introduceti gitPath: ";
	cin >> gitPath;
	cout << "Introduceti noOfBranches: ";
	cin >> noOfBranches;
	cout << "Introduceti totalNoOfCommits: ";
	cin >> totalNoOfCommits;
	Project p(gitPath, noOfBranches, totalNoOfCommits);
	s.addProject(p);
	n++;
	cout << endl;
}

//afisare toate elementele de tip Project
void UI::getAll(Service& s)
{
	cout << endl << "Proiectele sunt: " << endl;
	for (int i = 0; i < s.getSize(); i++) {
		cout << s.getAll()[i] << " ";
		cout << endl;
	}

	cout << endl;
}

//stergere element de tip Project
void UI::delProject(Service& s)
{
	cout << "Sterge proiectul cu numarul: ";
	int i; cin >> i; int n = s.getSize();
	s.delProject(s.getItemFromPos(i - 1)); n -= 1;
}

//modificare element de tip Project
void UI::updateProject(Service& s)
{
	cout << "Update la proiectul cu numarul: "; int i; cin >> i;
	Project p = s.getItemFromPos(i - 1);
	cout << "new gitPath: "; char  newGitPath[100];  cin >> newGitPath;
	cout << "new noOfBranches: "; int newNoOfBranches;  cin >> newNoOfBranches;
	cout << "new totalNoOfCommits: "; int newTotalNoOfCommits;  cin >> newTotalNoOfCommits;
	s.updateProject(p, newGitPath, newNoOfBranches, newTotalNoOfCommits);
}

//afisare elementelor care au cel putin K branch-uri si L commit-uri
void UI::filterProjects(Service& s)
{
	int k, l, resultLen = 0;
	Project result[10];
	cout << "Introduceti K: " << endl;
	cin >> k;
	cout << "Introduceti L: " << endl;
	cin >> l;
	int n = s.getSize();
	s.filterProjects(k, l, s, n, result, resultLen);
	cout << endl << "Proiectele care au cel ptuin " << k << " branch-uri si " << l << " commit-uri sunt: " << endl;
	for (int i = 0; i < resultLen; i++) {
		cout << result[i] << " ";
		cout << endl;
	}
	cout << endl;
}

//stergerea proiectelor care au noOfBranches*totalNoOfCommits = 0
void UI::delProjects(Service& s)
{
	int n = s.getSize();
	s.delProjects(s, n);
}
