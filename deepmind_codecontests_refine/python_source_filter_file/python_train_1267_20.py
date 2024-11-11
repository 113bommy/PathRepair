######################################################################
# Write your code here
import sys
input = sys.stdin.readline
#import resource
#resource.setrlimit(resource.RLIMIT_STACK, [0x10000000, resource.RLIM_INFINITY])
#sys.setrecursionlimit(0x100000)
# Write your code here
RI = lambda : [int(x) for x in sys.stdin.readline().strip().split()]
rw = lambda : input().strip().split()
#from collections import defaultdict as df
#import heapq 
#heapq.heapify(li) heappush(li,4) heappop(li)
#import random
#random.shuffle(list)
infinite = float('inf')
#######################################################################

n,x,y=RI()

l=RI()
pre=[1]*n


pre[0]=1
for i in range(n):
    for j in range(max(0,i-x),i):
        if(l[j]<=l[i]):
            pre[i]=0
            continue

pos=[1]*n


pos[n-1]=1
for i in range(n-1,-1,-1):
    for j in range(i+1,min(n,i+y)):
        if(l[j]<=l[i]):
            pos[i]=0
            continue


for i in range(n):
    if(pre[i]==1 and pos[i]==1):
        print(i+1)
        break

        
        
    
        
