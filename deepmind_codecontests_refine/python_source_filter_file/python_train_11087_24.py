import sys
import math
import random
#sys.setrecursionlimit(1000000)
input = sys.stdin.readline
 
############ ---- USER DEFINED INPUT FUNCTIONS ---- ############
def inp():
    return(int(input()))
def inara():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))
################################################################
############ ---- THE ACTUAL CODE STARTS BELOW ---- ############

n=inp()
ara=inara()

ans=[0]*n
curr=0

for i in range(n-1,-1,-1):
	if ara[i]<curr:
		ans[i]=curr-ara[i]+1
	curr=max(curr,ara[i])

print(*ans)
