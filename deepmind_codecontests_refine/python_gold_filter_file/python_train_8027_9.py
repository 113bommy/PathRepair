# TAIWAN NUMBER ONE!!!!!!!!!!!!!!!!!!!
# TAIWAN NUMBER ONE!!!!!!!!!!!!!!!!!!!
# TAIWAN NUMBER ONE!!!!!!!!!!!!!!!!!!!
from sys import stdin, stdout
from math import sqrt
import math
import heapq
from itertools import accumulate



#N = int(input())

#s = input() 
N,K = [int(x) for x in stdin.readline().split()]

arr = [int(x) for x in stdin.readline().split()]

summ = sum(arr)

if summ%K!=0:
    print('No')
    quit()

div = summ//K

s = 0
ans = []
k = 0
for i in range(N):
    s += arr[i]
    k += 1
    if s==div:
        ans.append(k)
        s = 0
        k = 0
    
    if s>div:
        print('No')
        quit()
        
print('Yes')
print(*ans)
    


    
            