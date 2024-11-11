'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

######################################################################
# Write your code here
import sys
#import resource
#resource.setrlimit(resource.RLIMIT_STACK, [0x10000000, resource.RLIM_INFINITY])
#https://stackoverflow.com/questions/3323001/what-is-the-maximum-recursion-depth-in-python-and-how-to-increase-it
sys.setrecursionlimit(0x100000)
# Write your code here
RI = lambda : [int(x) for x in input().strip().split()]
from collections import defaultdict as df
import heapq 
#heapq.heapify(li) heappush(li,4) heappop(li)
import random
#random.shuffle(list)
infinite = float('inf')
######################################################################3
t=int(input())

for i in range(t):
    n,k=RI()

    count=0
    while(n>0):
        temp=n%k
        count+=temp
        n-=temp
        n=n//k
        if(n!=0):
            count+=1

    print(int(count))
