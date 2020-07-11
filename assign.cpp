#include<bits/stdc++.h>
#include<list>
#include<iterator>
using namespace std;

class Student{
	public:
		string name;
		int age;
		int marks;
		string rollNumber;

		Student(string n, int a, int m, string rn){
			name = n;
			age = a;
			marks = m;
			rollNumber = rn;
		}

};

void printlist(list<Student> s) 
{
	list<Student>::iterator it; 
	int count = 1;
	for(it = s.begin(); it != s.end(); ++it){
		cout<<"Student "<<count<<" is : ";
		cout<<(*it).name<<", "<<(*it).age<<", "<<(*it).marks<<", "<<(*it).rollNumber<<endl;
		count++;
	}
} 

bool sortByName(Student A, Student B){
    return (A.name <= B.name);
}

bool sortByAge(Student A, Student B){
    return (A.age <= B.age);
}

bool sortByMarks(Student A, Student B){
    return (A.marks <= B.marks);
}

bool sortByRN(Student A, Student B){
    return (A.rollNumber <= B.rollNumber);
}

list<Student> sortFunc(list<Student> students,vector<string> criteria){
	int i, n = criteria.size();
	for(i=0; i<n; i++){
		if(criteria[i]=="name"){
			students.sort(sortByName);
		}
		else if(criteria[i]=="age"){
			students.sort(sortByAge);
		}
		else if(criteria[i]=="marks"){
			students.sort(sortByMarks);
		}
		else if(criteria[i]=="rollNumber"){
			students.sort(sortByRN);
		}
	}
	return students;
}

int main(){
	cout<<"*****Start of main function*****"<<endl;
	cout<<endl<<"Enter number of students, you want to enter : ";
	int n;
	cin>>n;
	string name, rn;
	int age, marks;
	list<Student> slist;
	while(n--){
		cout<<"Enter name of student : ";
		cin>>name;
		cout<<"Enter age of student : ";
		cin>>age;
		cout<<"Enter marks of student : ";
		cin>>marks;
		cout<<"Enter rollNumber of student : ";
		cin>>rn;
		Student obj(name, age, marks, rn);
		slist.push_back(obj);
		cout<<endl;
	}

	cout<<endl<<"student list before sorting"<<endl;
	printlist(slist);
	cout<<endl;

	vector<string> criteria;
	cout<<"How many criteria do you want to enter : ";
	cin>>n;
	while(n--){
		cout<<"Enter criteria strings you want to enter : ";
		cin>>name;
		criteria.push_back(name);
	}

	list<Student> output = sortFunc(slist, criteria);

	cout<<endl<<"student list after sorting"<<endl;
	printlist(output);

	cout<<endl<<"*****Ending of main function*****"<<endl;
	return 0;
}	
