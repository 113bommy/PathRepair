import sys
import math
#from queue import *
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

fib=[0,1]

now=0

while now<=1000000000:
	now=fib[-1]+fib[-2]
	fib.append(now)

n=inp()

for a in fib:
	for b in fib:
		for c in fib:
			if a+b+c==n:
				print(a,b,c)
				exit(0)

print("I'm too stupid to solve this problem")
	
	
