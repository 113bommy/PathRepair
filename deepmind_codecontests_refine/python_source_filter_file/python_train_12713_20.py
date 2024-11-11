# TAIWAN NUMBER ONE!!!!!!!!!!!!!!!!!!!
# TAIWAN NUMBER ONE!!!!!!!!!!!!!!!!!!!
# TAIWAN NUMBER ONE!!!!!!!!!!!!!!!!!!!
from sys import stdin, stdout
import math
import heapq
from itertools import accumulate

#N = int(input())
#s = input() 
N,K = [int(x) for x in stdin.readline().split()]

R = N*2
G = N*5
B = N*8

res = 0
res += (N*2)//K + 1*((2*N)%K==0)
res += (N*5)//K + 1*((5*N)%K==0)
res += (N*8)//K + 1*((8*N)%K==0)

print(res)