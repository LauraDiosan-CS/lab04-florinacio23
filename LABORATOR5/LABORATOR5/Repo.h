#pragma once
#include "Project.h"

class Repo {
private:
	Project projects[20];
	int n;
public:
	Repo();
	~Repo();
	void addProject(Project p);
	Project* getAll();
	int getSize();
	int findProject(Project p);
	void delProject(Project p);
	void updateProject(Project p, char* gitPath, int noOfBranches, int totalNoOfCommits);
	Project getItemFromPos(int i);
};
