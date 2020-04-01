#include "Service.h"
#include <iostream>
using namespace std;

//constructor fara param
Service::Service() {
	this->r;
}

//destructor
Service::~Service() {
}

//adauga un element de tip Project
void Service::addProject(Project& p) {
	r.addProject(p);
}

//returneaza toate elementele de tip Project
Project* Service::getAll() {
	return r.getAll();
}

//sterge un element de tip Project 
void Service::delProject(Project p) {
	r.delProject(p);
}

//modifica un element de tip Project 
void Service::updateProject(Project& p, char* gitPath, int noOfBranches, int totalNoOfCommits) {
	r.updateProject(p, gitPath, noOfBranches, totalNoOfCommits);
}

//returneaza elementul de tip Project de pe o anumita pozitie
Project Service::getItemFromPos(int i) {
	return r.getItemFromPos(i);
}

//returneaza dimensiunea repo-ului
int Service::getSize() {
	return r.getSize();
}

//filtreaza elementele de tip Project care au cel putin K branch-uri si L commit-uri
void Service::filterProjects(int k, int l, Service& s, int n, Project result[], int& resultLen)
{
	resultLen = 0;
	for (int i = 0; i < n; i++) {
		Project x = s.getItemFromPos(i);

		if ((x.getNoOfBranches()) >= k && (x.getTotalNoOfCommits()) >= l) {
			result[resultLen] = x;
			resultLen++;
		}
	}
}

//sterge elementele de tip Project care au noOfBranches*totalNoOfCommits = 0
void Service::delProjects(Service& s, int& n) {
	Project* projects = s.getAll();
	int i = 0;
	while (i < n)
	{
		if ((projects[i].getNoOfBranches()) * (projects[i].getTotalNoOfCommits()) == 0) {
			s.delProject(projects[i]);
			n--;
		}
		else
			i++;
	}
}


