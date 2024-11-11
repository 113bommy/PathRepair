import sys 
#sys.stdin=open('in','r')
#sys.stdout=open('out','w')
#import math 
#import queue
#import random
#sys.setrecursionlimit(int(1e6))
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
m=inp()
a=[0]*n
for i in range(n):
	a[i]=inp()
mini=min(a)
hi=sum(a)+m
lo=mini
while hi>=lo:
	mid=(hi+lo)//2
	temp=m
	for x in a:
		if x<=mid:
			temp-=min(temp,mid-x)
	if temp==0:
		mini=mid
		hi=mid-1
	else:
		lo=mid+1
maxi=max(a)+m
print(mini,maxi)
