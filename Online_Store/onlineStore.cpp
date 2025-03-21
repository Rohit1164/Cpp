#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Product
{
  int productID;
  string name;
  string category;
};

struct Order
{
  int orderID;
  int productID;
  int quantity;
  string customerID;
  time_t orderDate;
};

int main()
{
  vector<Product> products = {
      {101, "Phone", "Electronics"},
      {102, "Computer", "Electronics"},
      {103, "Coffee Maker", "Kitchen"},
      {104, "Home Lamp", "Home"}};

  deque<string> recentCustomers = {"C001", "C002"};

  recentCustomers.push_back("C003");
  recentCustomers.push_back("C004");

  list<Order> orderHistory;

  orderHistory.push_back({1, 101, 1, "C001", time(0)});
  orderHistory.push_back({2, 102, 3, "C002", time(0)});
  orderHistory.push_back({3, 103, 1, "C003", time(0)});
  orderHistory.push_back({4, 104, 2, "C004", time(0)});

  set<string> categories;

  for (const auto &product : products)
  {
    categories.insert(product.category);
  }

  map<int, int> productStock = {
      {101, 10},
      {102, 8},
      {103, 2},
      {104, 5}};

  multimap<string, Order> customerOrders;

  for (const auto &order : orderHistory)
  {
    customerOrders.insert({order.customerID, order});
  }

  unordered_map<string, string> customerData = {
      {"C001", "Rohit"},
      {"C002", "Sohit"},
      {"C003", "Mohit"},
      {"C004", "Vikas"}};

  unordered_set<int> uniqueProductIDs;

  for (const auto &product : products)
  {
    uniqueProductIDs.insert(product.productID);
  }

  // Displaying product categories
  cout << "Product Categories:\n";
  for (const auto &category : categories)
  {
    cout << "- " << category << endl;
  }

  // Displaying product stock
  cout << "\nProduct Stock Levels:\n";

  // Display product stock levels (without structured bindings)
  for (const pair<int, int> &entry : productStock)
  {
    cout << "Product ID: " << entry.first << " | Stock: " << entry.second << endl;
  }

  // Display recent customers
  cout << "\nRecent Customers:\n";
  for (const auto &customer : recentCustomers)
  {
    cout << "- " << customerData[customer] << " (" << customer << ")\n";
  }

  // Display customer orders (without structured bindings)
  cout << "\nCustomer Orders:\n";
  for (const pair<const string, Order> &entry : customerOrders)
  {
    cout << "Customer: " << customerData[entry.first] << " | Order ID: " << entry.second.orderID
         << " | Product ID: " << entry.second.productID << " | Quantity: " << entry.second.quantity << "\n";
  }

  return 0;
}
