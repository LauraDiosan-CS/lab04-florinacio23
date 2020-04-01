#pragma once
#include "Project.h"
#include "Repo.h"

class Service {
private:
	Repo r;
public:
	Service();
	~Service();
	void addProject(Project& p);
	Project* getAll();
	void delProject(Project p);
	void updateProject(Project& p, char* gitPath, int noOfBranches, int totalNoOfCommits);
	Project getItemFromPos(int i);
	int getSize();
	void filterProjects(int k, int l, Service& s, int n, Project result[], int& resultLen);
	void delProjects(Service& s, int& n);
};
#pragma once
