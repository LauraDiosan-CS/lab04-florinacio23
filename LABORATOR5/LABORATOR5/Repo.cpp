#include "Repo.h"
#include <iostream>
using namespace std;

//constructor fara param
Repo::Repo() {
	this->n = 0;
}

//destructor
Repo::~Repo() {
	this->n = 0;
}

//adaugarea unui element de tip Project
void Repo::addProject(Project p) {
	this->projects[this->n++] = p;
}

//returneaza toate elementele de tip Project
Project* Repo::getAll() {
	return this->projects;
}

//returneaza dimensiunea repo-ului
int Repo::getSize() {
	return n;
}

//returneaza pozitia unui element de tip Project
int Repo::findProject(Project p) {
	int i = 0;

	while (i < n) {
		if (projects[i] == p)
			return i;
		i++;
	}
	return -1;
}

//sterge un element de tip Project
void Repo::delProject(Project p) {
	int i = findProject(p);
	if (i != -1) {
		projects[i] = projects[n - 1];
		n--;
	}

}

//modifica un element de tip Project
void Repo::updateProject(Project p, char* gitPath, int noOfBranches, int totalNoOfCommits) {
	int i = findProject(p);
	projects[i].setGitPath(gitPath);
	projects[i].setNoOfBranches(noOfBranches);
	projects[i].setTotalNoOfCommits(totalNoOfCommits);
}

//returneaza elementul de tip Project de pe o anumita pozitie
Project Repo::getItemFromPos(int i) {
	return projects[i];
}