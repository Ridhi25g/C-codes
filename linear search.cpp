#include <iostream>

using namespace std;

int
main ()
{
  int A[50], ch, key, n, i, pos = -1;
  cout << "1.LINEAR SEARCH\n";

  cout << "Enter the size of array : ";
  cin >> n;
  cout << "Enter the array\n";
  for (i = 0; i < n; i++)
    {
      cin >> A[i];
    }
  cout << "Enter the element to be searched : ";
  cin >> key;
  for (i = 0; i < n; i++)
    {
      if (A[i] == key)
	{
	  pos = i;
	  break;
	}
    }
  if (pos != -1)
    cout << "Element found at " << pos + 1;
  else
    cout << "Element not found";

  return 0;
}


