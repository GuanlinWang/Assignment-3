#include "person.cpp"
#include <iostream>
#include <fstream>
#include<vector>
#include<iomanip>
#include <algorithm>


void readData(vector <Person> &emp);
void getCompanyName(vector <Person> &emp, vector<string> &comp);
void printHighestPaid(vector<Person> &emp);
void separateAndSave(vector <Person> &emp, vector<string> &comp);

int main()
{
   vector <Person> employees;
   vector <string> companyNames;
   readData(employees);
   getCompanyName(employees, companyNames);
   printHighestPaid(employees);
   separateAndSave(employees,companyNames);

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
    if(count(comp.begin(),comp.end(),emp.at(i).getCompanyName())<1)
    {
       comp.push_back(emp.at(i).getCompanyName());
    }
  }

  for(int i=0; i<comp.size();i++)
  {
    cout<<comp.at(i)<<" ";
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
      <<"Total Pay: $"<<setprecision(2)<<fixed<<highest<<endl;
}

void separateAndSave(vector <Person> &emp, vector<string> &comp)
{
  float Boeing=0,Douglas=0,HealthTech=0,Intel=0,Raytheon=0;
  fstream file;
  for (int i =0; i<emp.size();i++)
  {
    for (int k=0; k<comp.size();k++)
    {
    if (emp.at(i).getCompanyName()==comp.at(k))
      {
         file.open(comp.at(k)+".txt",fstream::app);

          file<<setw(20)<<left<<emp.at(i).fullName()<<" "<<setw(4)<<emp.at(i).getEmployeeId()<<"   "<<setw(12)<<comp.at(k)<<"    $"<<emp.at(i).totalPay()<<endl;
          file.close();

           if (comp.at(k)=="Boeing")
             {Boeing+=emp.at(i).totalPay();}
             else if(comp.at(k)=="Douglas")
             {Douglas+=emp.at(i).totalPay();}
             else if (comp.at(k)=="HealthTech")
             {HealthTech+=emp.at(i).totalPay();}
             else if(comp.at(k)=="Intel")
             { Intel+=emp.at(i).totalPay();}
             else if(comp.at(k)=="Raytheon")
             {Raytheon+=emp.at(i).totalPay();
             break;
      }
     }
  }
}

 for (int i=0;i<comp.size();i++)
 {
      if (comp.at(i)=="Boeing")
      {
        file.open(comp.at(i)+".txt",fstream::app);
        file<<"Total  $"<<Boeing<<endl;
        file.close();
      }
      else if(comp.at(i)=="Douglas")
      {
        file.open(comp.at(i)+".txt",fstream::app);
        file<<"Total  $"<<Douglas<<endl;
          file.close();
    }
      else if (comp.at(i)=="HealthTech")
      {
        file.open(comp.at(i)+".txt",fstream::app);
        file<<"Total  $"<<HealthTech<<endl;
          file.close();
      }
      else if(comp.at(i)=="Intel")
      {
        file.open(comp.at(i)+".txt",fstream::app);
        file<<"Total  $"<<Intel<<endl;
          file.close();
      }
      else if(comp.at(i)=="Raytheon")
      {
        file.open(comp.at(i)+".txt",fstream::app);
        file<<"Total  $"<<Raytheon<<endl;
          file.close();
      }
 }
}
