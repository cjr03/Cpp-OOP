//
//  main.cpp
//  Homework3
//
//  Created by Cole Roberts on 1/25/25.
//

#include <iostream>
#include "line.h"
using namespace std;

int main()
{
  const int SIZE(5);
  line l[SIZE];

  l[0] = line(0, 0, 0, 1);
  l[1] = line(0, 1);
  l[2] = line(1, 2, 3);
  l[3] = line();
  cout << "Please enter '3 1 4 2': ";
  cin >> l[4];

  for (int i = 0; i < SIZE; ++i)
    {
      cout << "Line " << i << " (in standard form): ";
      cout << l[i] << endl;
  
      if (l[i].is_vertical())
    cout << "\t is vertical" << endl;
      if (l[i].is_horizontal())
    cout << "\t is horizontal" << endl;

      if (!l[i].is_vertical())
    {
      cout << "\t slope = " << l[i].slope() << endl;
      cout << "\t y-intercept = " << l[i].y_intercept() << endl;
    }
      if (!l[i].is_horizontal())
    cout << "\t x-intercept = " << l[i].x_intercept() << endl;
      cout << endl;
    }

   cout << "Line 2 is parallel to: ";
   for (int i = 0; i < SIZE; ++i)
     if (l[2].is_parallel_to(l[i]))
       cout << "line " << i << "   ";
   cout << endl;

   cout << "Does line 2 contain its x-intercept: ? " << l[2].contains(l[2].x_intercept(), 0) << endl;
   cout << "Does line 2 contain its y-intercept: ? " << l[2].contains(0, l[2].y_intercept()) << endl;

  return 0;
}
