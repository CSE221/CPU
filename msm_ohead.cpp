#include <stdio.h>
#include <iostream>
#include <stdint.h>

//define rdtsc() 
 __inline__ uint64_t rdtsc() {
    uint32_t low, high;
    __asm__ __volatile__ (
        "xorl %%eax,%%eax \n    cpuid"
        ::: "%rax", "%rbx", "%rcx", "%rdx" );
    __asm__ __volatile__ (
                          "rdtsc" : "=a" (low), "=d" (high));
    return (uint64_t)high << 32 | low;
}


using namespace std; 

//using rdtsc to record loop time 
int main()
{
    int N = 10000;
    int cycle_cnt1 = 0, cycle_cnt2 = 0;
    float  cycle_cnt = 0.0; 
   // cycle_cnt1 = rdtsc();
   // cycle_cnt2 = rdtsc();
   // cycle_cnt = cycle_cnt2 - cycle_cnt1; //test for one time 
   // cout << "One time test " << cycle_cnt << endl;    
   
    cycle_cnt = 0.0;  
    for(int i=0; i<N; i++)
    { 
       cycle_cnt1 = rdtsc();
       cycle_cnt2 = rdtsc();
       cycle_cnt += cycle_cnt2 - cycle_cnt1; //test for N time 
      // cout << "Loop test " << cycle_cnt << endl; 
    }  
    cycle_cnt = cycle_cnt/N;  
    cout << "Loop test " << cycle_cnt << endl; 
    return 0; 
}


