#pragma once
#include <ostream>
using namespace std;

class Project {
private:
	char* gitPath;
	int noOfBranches;
	int totalNoOfCommits;
public:
	Project();
	Project(const char* gitPath, int noOfBranches, int totalNoOfCommits);
	Project(const Project& p);
	~Project();
	char* getGitPath();
	int getNoOfBranches();
	int getTotalNoOfCommits();
	void setGitPath(const char* gitPath);
	void setNoOfBranches(int noOfBranches);
	void setTotalNoOfCommits(int totalNoOfCommits);
	Project& operator=(const Project& p);
	bool operator==(const Project& p);
	friend ostream& operator<<(ostream& os, const Project& p);
};
#pragma once
#pragma once
