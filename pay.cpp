#include "person.cpp"
#include <iostream>
#include <fstream>
#include<vector>
#include<iomanip>

void readData(vector <Person> &emp);
void getCompanyName(vector <Person> &emp, vector<string> &comp);
void printHighestPaid(vector<Person> &emp);
int main()
{
   vector <Person> employees;
   vector <string> companyNames;
   readData(employees);
   getCompanyName(employees, companyNames);
   printHighestPaid(employees);

}

void readData(vector <Person> &emp)
{
  string first,last,company;
  int id;
  float hours, rate;
  Person temp;
  ifstream file;
  file.open("input.txt");

  for(int i =0; i<200;i++)
  {
    file>>last>>first>>id>>company>>rate>>hours;
    if(file.peek(),file.eof ())
    {
     break;
   }
    emp.push_back(temp);
    emp.at(i).setFirstName(first);
    emp.at(i).setLastName(last);
    emp.at(i).setEmployeeId(id);
    emp.at(i).setCompanyName(company);
    emp.at(i).setHoursWorked(hours);
    emp.at(i).setPayRate(rate);

  }
  file.close();
}
void getCompanyName(vector <Person> &emp, vector<string> &comp)
{

  for (int i =0;i<emp.size();i++)
  {
     comp.push_back(emp.at(i).getCompanyName());
  }
}
void printHighestPaid(vector<Person> &emp)
{
  float highest=emp.front().totalPay();
  int id;
  string name, comp;
  for (int i =1; i<emp.size();i++)
  {
     if (emp.at(i).totalPay()>highest)
     {
       highest=emp.at(i).totalPay();
       id=emp.at(i).getEmployeeId();
       name=emp.at(i).fullName();
       comp=emp.at(i).getCompanyName();
     }
  }

  cout<<"Highest paid: "<<name<<endl
      <<"Employee Id: "<<id<<endl
      <<"Employer: "<<comp<<endl
      <<"Total Pay: $"<<setprecision(2)<<fixed<<highest;
}
