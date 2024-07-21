#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAX_FIB_SIZE 100

long fibonacci_iterative(long n)
{
    long temp;
    long n1 = 0;
    long n2 = 1;

    if (n == 0)
        return 0;

    if (n == 1)
      return 1;

   for (long i = 1; i < n; ++i)
   {
      temp = n1 + n2;
      n1 = n2;
      n2 = temp;
   }

   return n2;
}

long fibonacci_recursive(long n, long fib[])
{
   if (n > MAX_FIB_SIZE) {
      return -1;
   }

   long result;
   if (n == 0) {
      result = 0;
   }
   else if (n == 1) {
      result = 1;
   } else {
      if (fib[n - 1] < 0) {
         result = fibonacci_recursive(n - 1, fib) + fibonacci_recursive(n - 2, fib);
         fib[n - 1] = result;
      } else {
         result = fib[n -1];
      }
   }

   return result;
}

int palindrome_iterative(char str[]) {
    int low = 0;
    int high = strlen(str) - 1;


   while (low < high) {
      if (str[low] != str[high]) {
            return 0;
        }
        low++;
       high--;
   }
   return 1;
}

int palindrome_recursive(char str[], int l, int h)
{
    if (l >= h)
        return 1;

    if (str[l] != str[h])
        return 0;

    return palindrome_recursive(str, l + 1, h - 1);
}


int main()
{
   long fib[MAX_FIB_SIZE];
   for (int i = 0; i < MAX_FIB_SIZE; i++) {
      fib[i] = -1;
   }

   assert(fibonacci_iterative(0) == 0);
   assert(fibonacci_iterative(1) == 1);
   assert(fibonacci_iterative(2) == 1);
   assert(fibonacci_iterative(3) == 2);
   assert(fibonacci_iterative(5) == 5);
   assert(fibonacci_iterative(10) == 55);
   assert(fibonacci_iterative(30) == 832040);
   assert(fibonacci_iterative(47) == 2971215073);

   assert(fibonacci_recursive(0, fib) == 0);
   assert(fibonacci_recursive(1, fib) == 1);
   assert(fibonacci_recursive(2, fib) == 1);
   assert(fibonacci_recursive(3, fib) == 2);
   assert(fibonacci_recursive(5, fib) == 5);
   assert(fibonacci_recursive(10, fib) == 55);
   assert(fibonacci_recursive(30, fib) == 832040);
   assert(fibonacci_recursive(47, fib) == 2971215073);

   assert(palindrome_iterative("abcba") == 1);
   assert(palindrome_iterative("racecar") == 1);
   assert(palindrome_iterative("noon") == 1);

   assert(palindrome_recursive("abcba", 0, 4) == 1);
   assert(palindrome_recursive("racecar", 0, 6) == 1);
   assert(palindrome_recursive("noon", 0, 3) == 1);
}