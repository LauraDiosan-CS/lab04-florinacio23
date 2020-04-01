#include "Project.h"
#include "Repo.h"
#include "Service.h"
#include <iostream>
#include <assert.h>
#include "tests.h"
using namespace std;

//teste constructori
void testConstructors() {
	Project p1; //constructor implicit
	assert((p1.getGitPath() == NULL) && (p1.getNoOfBranches() == 0) && (p1.getTotalNoOfCommits() == 0));
	char a[10] = "git";
	Project p2(a, 5, 10); //constructor cu param
	assert((strstr(p2.getGitPath(), "git")) && (p2.getNoOfBranches() == 5) && (p2.getTotalNoOfCommits() == 10));
	Project p3(p2); //constructor de copiere
	assert(p3 == p2);
}

//teste setteri, getteri
void testSetGet() {
	Project p; char a[10] = "git";
	p.setGitPath(a);
	p.setNoOfBranches(52);
	p.setTotalNoOfCommits(300);
	assert((strstr(p.getGitPath(), "git")) && (p.getNoOfBranches() == 52) && (p.getTotalNoOfCommits() == 300));
}

//test operator de egalitate
void testEqual() {
	char a[10] = "git1"; char b[10] = "git2";
	Project p1(a, 3, 1);
	Project p2(b, 12, 43);
	p1 = p2;
	assert((strstr(p1.getGitPath(), "git2")) && (p1.getNoOfBranches() == 12) && (p1.getTotalNoOfCommits() == 43));
}

//teste repository
void testRepo() {
	Repo r;
	char a[10] = "git1"; char b[10] = "git2";
	Project p(a, 10, 20);
	r.addProject(p); //adaugare
	assert(r.getSize() == 1); //dimensiune
	Project p1(a, 11, 51);
	r.addProject(p1);
	assert(r.getSize() == 2);
	Project* res; res = r.getAll(); //getAll
	assert(res[0] == p && res[1] == p1);
	r.delProject(p1); //stergere
	assert(r.getSize() == 1);
	assert((strstr(p.getGitPath(), "git1")) && (p.getNoOfBranches() == 10) && (p.getTotalNoOfCommits() == 20));
	r.updateProject(p, b, 20, 50);	//update
	assert((strstr(r.getItemFromPos(0).getGitPath(), "git2")) && (r.getItemFromPos(0).getNoOfBranches() == 20) && (r.getItemFromPos(0).getTotalNoOfCommits() == 50));
	assert(r.findProject(r.getItemFromPos(0)) == 0); //gasire pozitie a unui elem Project
}

//teste service
void testService()
{
	Service s;
	char a[10] = "git1"; char b[10] = "git2";
	Project p(a, 10, 20); //creare obiect de tip Project 
	s.addProject(p); //adaugare 
	assert(s.getSize() == 1);
	Project p1(a, 11, 51);
	s.addProject(p1);
	assert(s.getSize() == 2);
	Project* res; res = s.getAll(); //getAll
	assert(res[0] == p && res[1] == p1);
	s.delProject(p1); //stergere
	assert(s.getSize() == 1);
	assert((strstr(p.getGitPath(), "git1")) && (p.getNoOfBranches() == 10) && (p.getTotalNoOfCommits() == 20));
	s.updateProject(p, b, 20, 30); //update 
	assert((strstr(s.getItemFromPos(0).getGitPath(), "git2")) && (s.getItemFromPos(0).getNoOfBranches() == 20) && (s.getItemFromPos(0).getTotalNoOfCommits() == 30));
	Project p2(a, 120, 0);
	s.addProject(p2);
	Project result[10]; int lenResult = 0;
	s.filterProjects(10, 10, s, s.getSize(), result, lenResult); //filtrare Projects care au cel putin K branch-uri si L commit-uri
	assert(lenResult == 1);
	int n = s.getSize();
	s.delProjects(s, n); //stergere Projects care au noOfBranches*totalNoOfCommits = 0
	assert(n == 1);
}


void tests() {
	testConstructors();
	testSetGet();
	testEqual();
	testRepo();
	testService();
	cout <<"... all tests are good ... " << endl << endl;
}
