#include <stdio.h>
#include <iostream.h>

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




//using rdtsc to record loop time 
int main()
{
    N = 10000;
    int cycle_cnt1 = 0, cycle_cnt2 = 0, cycle_cnt = 0; 
    cycle_cnt1 = rdtsc();
    cycle_cnt2 = rdtsc();
    cycle_cnt = cycle_cn1 - cycle_cnt2; //test for one time 
    
    for(int i=0; i<N; i++)
    { 
       cycle_cnt1 = rdtsc();
       cycle_cnt2 = rdtsc();
       cycle_cnt = cycle_cn1 - cycle_cnt2; //test for N time 
    }  


}


