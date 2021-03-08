#include <iostream>

using namespace std;

//Declare function
int search(int arr[], int head, int tail, int key);

int main() {
  int n; //Size of array
  int key; //Key number to search for

  //Ask for input: size of array
  cout << "How many numbers are there in your array? ";
  cin >> n;
  cout << "\n";
  
  //Ask for input: get specific numbers for the array
  cout << "Please input " << n << " distinct numbers in ascending order (small to large).\n";

  int numbers[n]; //Array to save all numbers
  for (int i = 0; i < n; i++)
  {
    cout << "Enter number for position #" << i << ": ";
    cin >> numbers[i];
  }
  cout << "\n";

  //Ask for input: key number to search for
  cout << "Input the number you want to find: ";
  cin >> key;
  cout << "\n";
    
  //Search for key and save output into "location"
  int location =-1;
  location = search(numbers, 0, n, key);

  //Print output: 
  cout << "Result:\n";

  //If found, print index number
   if(location != -1)
   {
      cout << "Index location of " << key << " is: " << location << "\n";
   }

   //If not found
   else
   {
      cout<< key <<" doesn't exist in the array.\n";
   }
   return 0;
}

//Binary search function
int search(int arr[], int head, int tail, int key)
{
   int mid;
   if(tail >= head)
   {
     //Get middle index
      mid = int((head + tail)/2);
      
      //Check if key found at the middle index:
      if(arr[mid] == key)
      {
         return mid;
      }

      //If not found, check if key is in the greater half (start from mid+1, keep the tail)
      else if(arr[mid] < key)
      {
         return search(arr,mid+1,tail,key);
      }

      //If not found, check if key is in the smaller half (keep the head, end at mid-1)
      else
      {
         return search(arr,head,mid-1,key);
      }
   }
   
   //Return error if function input parameters are wrong (tail < head)
   return -1;
}