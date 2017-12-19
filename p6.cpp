// James Mathew
// p6.cpp
// This program utilizes the list from c++ stl to store 1000 random values.
// 	then it removes all multiples of five from the list. then removes all the
//	prime numbers that are in between two numbers of mixed parity.

#include <iostream>
#include <list>

using namespace std;
void print(list<int> nums); // prints nums onto the screen.
// checks if int x is a prime or not, returns true if x is prome, else false
bool checkPrime(int x); 

int main ()
{
  int max = 100;
  int size = 1000;
  
  srand(time(0));
  list<int> nums;
  // adds all the values to the list.
  for (int i = 0; i < size; i++) {
    nums.push_front(rand() % max);
  }
  list<int>::iterator it;
  print(nums);
  //removes multiples of 5
  for (it = nums.begin(); it != nums.end();) {
    if (*it % 5 == 0) {
      it = nums.erase(it);
    } else {
      ++it;
    }
  }
  print(nums);
  bool x = true;
  while (x) {
    x  = false;
    it = nums.begin();
    int pre = *it;
    it++;
    int cur = *it;
    it++;
    int nxt = *it;
    it--;
    while(it != (--nums.end())) {
      if (checkPrime(cur) && ((pre % 2 == 0 && nxt % 2 != 0)||
                              (pre % 2 != 0 && nxt % 2 == 0))) {
        x = true;
        it = nums.erase(it); // removes the value
        cur = *it;
        it++;
        nxt = *it;
        it--;
      } else {
        pre = *it;
        it++;
        cur = *it;
        it++;
        nxt = *it;
        it--;
      }
    }
    print(nums);
  }
}

bool checkPrime(int x)
{
  int y = 2;
  while (y < x) {
    if (x % y == 0) {
      return false;
    }
    y++;
  }
  return true;
  
}

void print (list<int> nums) 
{
  list<int>::iterator it;
  int indx = 25;
  int count = 0;
  for (it = nums.begin(); it != nums.end(); it++){
    cout << *it << " ";
    count++;
    if (count % indx == 0) {
      cout << endl;
    }
  }
  cout << endl;
}
