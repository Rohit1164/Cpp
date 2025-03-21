#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>

using namespace std;

struct Employee
{

  int id;
  string name;
  double salary;
};

void displayEmployee(const Employee &emp)
{
  cout << "\n ID: " << emp.id << " , Name : " << emp.name << ", Salary " << "$" << emp.salary;
}

int main()
{
  vector<Employee> employees = {
      {101, "Rohit", 120000},
      {102, "Sohit", 240000},
      {103, "Mohit", 100000},
      {104, "Ubhay", 50000},
      {105, "Abhiy", 20000}};

  // Lambda Function
  sort(
      employees.begin(),
      employees.end(),
      [](const Employee &e1, const Employee &e2)
      { return e1.salary > e2.salary; });

  cout << "\n Employee sorted by salary -> Higest to lowest \n";

  for_each(employees.begin(), employees.end(), displayEmployee);

  vector<Employee> highEarner;

  copy_if(
      employees.begin(),
      employees.end(),
      back_inserter(highEarner),
      [](const Employee &emp)
      { return emp.salary > 50000; });
  cout << "\n \n Employee who are high earners \n";

  for_each(highEarner.begin(), highEarner.end(), displayEmployee);

  double TotalSalary = accumulate(
      employees.begin(),
      employees.end(),
      0.0,
      [](double sum, const Employee &emp)
      { return sum + emp.salary; });

  double averageSalary = TotalSalary / employees.size();

  auto highestPaidSalary = max_element(
      employees.begin(),
      employees.end(),
      [](const Employee &emp1, const Employee &emp2)
      { return emp1.salary < emp2.salary; });

  return 0;
}