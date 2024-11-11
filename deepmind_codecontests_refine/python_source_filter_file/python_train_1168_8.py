import sys
import math
import heapq
import collections
fast_reader = sys.stdin.readline
fast_writer = sys.stdout.write
def input():
	return fast_reader().strip()
def print(*argv):
	fast_writer(' '.join((str(i)) for i in argv))
	fast_writer('\n')
def printspace(*argv):
	fast_writer(' '.join((str(i)) for i in argv))
	fast_writer(' ')
def inputnum():
    return(int(input()))
def inputnums():
    return(map(int,input().split()))
def inputlist():
    return(list(map(int,input().split())))
def inputstring():
    return([x for x in input()])
def inputstringnum():
    return([ord(x)-ord('a') for x in input()])
def inputmatrixchar(rows):
    arr2d = [[j for j in input().strip()] for i in range(rows)] 
    return arr2d
def inputmatrixint(rows):
    arr2d = []
    for _ in range(rows):
        arr2d.append([int(i) for i in input().split()])
    return arr2d
    
t = int(input())
for q in range(t):
    a, b, p = inputnums()
    s1 = inputstring()
    s = ['Z'] + s1
    l = len(s)
    cur = 0
    for i in reversed(range(l-1)):
        if s[i] != s[i-1]:
            if s[i] == 'B':
                cur += b 
                if cur > p:
                    break
                else:
                    l = i+1
            else:
                cur += a 
                if cur > p:
                    break
                else:
                    l = i+1
    print(l-1)