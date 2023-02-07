#include <iostream>

using namespace std;

bool iterativeBinarySearch(int arr[], int number, int low, int high)
{

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[mid] == number)
    {
      return true;
    }
    else if (arr[mid] < number)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return false;
}

bool recursiveBinarySearch(int arr[], int number, int low, int high)
{
  if (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[mid] == number)
    {
      return true;
    }
    if (arr[mid] > number)
    {
      return recursiveBinarySearch(arr, number, low, mid - 1);
    }
    else
    {
      return recursiveBinarySearch(arr, number, mid + 1, high);
    }
  }

  return false;
}

int main()
{ //  0 1 2 3 4  5  6  7  8  9  10 11 12 13 14
  int arr[15] = {1, 3, 4, 7, 12, 21, 25, 37, 42, 49, 51, 53, 57, 64, 65};

  cout << boolalpha << iterativeBinarySearch(arr, 49, 0, 14) << endl;
  cout << boolalpha << recursiveBinarySearch(arr, 49, 0, 14) << endl;

  return 0;
}
