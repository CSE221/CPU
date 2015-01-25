#include <stdio.h>
#include <iostream>
#include <stdint.h>

using namespace std;



//declare the rdtsc() 
__inline__  uint64_t    rdtsc(void) {
    uint32_t lo, hi; 
    __asm__ __volatile__ ("xorl %%eax,%%eax \n        cpuid"
                          ::: "%rax", "%rbx", "%rcx", "%rdx");
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return (uint64_t)hi << 32 | lo; 
}



void func0() {}
void func1(int a) {}
void func2(int a, int b) {}
void func3(int a, int b, int c) {}
void func4(int a, int b, int c, int d) {}
void func5(int a, int b, int c, int d, int e) {}
void func6(int a, int b, int c, int d, int e, int f) {}
void func7(int a, int b, int c, int d, int e, int f, int g) {}



int main(){
   int cyc_cnt1 = 0, cyc_cnt2 = 0, cyc_cnt = 0;
   int i = 0;   
   int a,b,c,d,e,f,g = 0; 
 
   cyc_cnt1 = rdtsc();
   for(int j=0; j<10000; j++)
   func0();
   cyc_cnt2 = rdtsc();
   cyc_cnt = cyc_cnt2- cyc_cnt1; 
   cout << "Procedure with " << i << " argument has " << cyc_cnt << "cycles" << endl; 
   i++;

      
   cyc_cnt1 = rdtsc();
   for(int j=0; j<10000; j++)
   func1(a);
   cyc_cnt2 = rdtsc();
   cyc_cnt = cyc_cnt2- cyc_cnt1; 
   cout << "Procedure with " << i << " argument has " << cyc_cnt << "cycles" << endl; 
   i++;   

   cyc_cnt1 = rdtsc();
   for(int j=0; j<10000; j++)
   func2(a,b);
   cyc_cnt2 = rdtsc();
   cyc_cnt = cyc_cnt2- cyc_cnt1; 
   cout << "Procedure with " << i << " argument has " << cyc_cnt << "cycles" << endl; 
   i++;

   cyc_cnt1 = rdtsc();
   for(int j=0; j<10000; j++)
   func3(a,b,c);
   cyc_cnt2 = rdtsc();
   cyc_cnt = cyc_cnt2- cyc_cnt1; 
   cout << "Procedure with " << i << " argument has " << cyc_cnt << "cycles" << endl; 
   i++;

   cyc_cnt1 = rdtsc();
   for(int j=0; j<10000; j++)
   func4(a,b,c,d);
   cyc_cnt2 = rdtsc();
   cyc_cnt = cyc_cnt2- cyc_cnt1; 
   cout << "Procedure with " << i << " argument has " << cyc_cnt << "cycles" << endl; 
   i++;

   cyc_cnt1 = rdtsc();
   for(int j=0; j<10000; j++)
   func5(a,b,c,d,e);
   cyc_cnt2 = rdtsc();
   cyc_cnt = cyc_cnt2- cyc_cnt1; 
   cout << "Procedure with " << i << " argument has " << cyc_cnt << "cycles" << endl; 
   i++;

   cyc_cnt1 = rdtsc();
   for(int j=0; j<10000; j++)
   func6(a,b,c,d,e,f);
   cyc_cnt2 = rdtsc();
   cyc_cnt = cyc_cnt2- cyc_cnt1; 
   cout << "Procedure with " << i << " argument has " << cyc_cnt << "cycles" << endl; 
   i++;

   cyc_cnt1 = rdtsc();
   for(int j=0; j<10000; j++)
   func7(a,b,c,d,e,f,g);
   cyc_cnt2 = rdtsc();
   cyc_cnt = cyc_cnt2- cyc_cnt1; 
   cout << "Procedure with " << i << " argument has " << cyc_cnt << "cycles" << endl; 
   
}


