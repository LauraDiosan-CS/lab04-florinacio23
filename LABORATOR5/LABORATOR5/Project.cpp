#include "Project.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;

//constructor default(fara param)
Project::Project() {
	this->gitPath = NULL;
	this->noOfBranches = 0;
	this->totalNoOfCommits = 0;
}

//constructor cu param
Project::Project(const char* gitPath, int noOfBranches, int totalNoOfCommits)
{
	this->gitPath = new char[strlen(gitPath) + 1];
	strcpy_s(this->gitPath, 1 + strlen(gitPath), gitPath);
	this->noOfBranches = noOfBranches;
	this->totalNoOfCommits = totalNoOfCommits;

}

//constructor de copiere
Project::Project(const Project& p) {
	if (p.gitPath) {
		this->gitPath = new char[strlen(p.gitPath) + 1];
		strcpy_s(this->gitPath, 1 + strlen(p.gitPath), p.gitPath);
	}
	this->noOfBranches = p.noOfBranches;
	this->totalNoOfCommits = p.totalNoOfCommits;

}

//destructor
Project::~Project() {
	if (gitPath) delete[]gitPath;
	gitPath = NULL;
	noOfBranches = -1;
	totalNoOfCommits = -1;
}

//getter pentru gitPath
char* Project::getGitPath() {
	return this->gitPath;
}

//getter pentru noOfBranches
int Project::getNoOfBranches() {
	return this->noOfBranches;
}

//getter pentru totalNoOfCommits
int Project::getTotalNoOfCommits() {
	return this->totalNoOfCommits;
}


//setter pentru nume
void Project::setGitPath(const char* gitPath)
{
	if (this->gitPath) {
		delete[] this->gitPath;
	}
	this->gitPath = new char[strlen(gitPath) + 1];
	strcpy_s(this->gitPath, strlen(gitPath) + 1, gitPath);
}

//setter pentru noOfBranches
void Project::setNoOfBranches(int noOfBranches) {
	this->noOfBranches = noOfBranches;
}

//setter pentru totalNoOfCommits
void Project::setTotalNoOfCommits(int totalNoOfCommits) {
	this->totalNoOfCommits = totalNoOfCommits;
}


//suprascrie operatorul "=" pentru un element de tip Project
Project& Project::operator=(const Project& p) {
	if (this == &p) return *this; //self-assignment
	if (gitPath) delete[] gitPath;
	if (p.gitPath) {
		this->gitPath = new char[strlen(p.gitPath) + 1];
		strcpy_s(gitPath, strlen(p.gitPath) + 1, p.gitPath);
	}
	noOfBranches = p.noOfBranches;
	totalNoOfCommits = p.totalNoOfCommits;
	return *this;
}

//operatorul de egalitate
bool Project:: operator==(const Project& p) {
	return strcmp(this->gitPath, p.gitPath) == 0 && this->noOfBranches == p.noOfBranches && this->totalNoOfCommits == p.totalNoOfCommits;
}

//pt afisare
ostream& operator<<(ostream& os, const Project& p)
{
	os << "GitPath : " << p.gitPath << ", noOfBranches : " << p.noOfBranches << ", totalNoOfCommits : " << p.totalNoOfCommits;
	return os;
}