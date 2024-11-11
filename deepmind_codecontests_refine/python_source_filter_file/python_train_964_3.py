from sys import stdin, stdout
import math
import heapq
import collections
input = stdin.readline
def inputnum():
    return(int(input()))
def inputnums():
    return(map(int,input().split()))
def inputlist():
    return(list(map(int,input().split())))
def inputstring():
    return([x for x in input()])
def inputstrings():
    return([x for x in input().split()])
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
    n, k = inputnums()
    s = inputstring()
    losingstreak = []
    winningstreak = 0
    wins = 0
    losses = 0
    curloss = 0
    for i in range(n):
        if s[i] == 'W':
            wins += 1 
            if i == 0 or s[i-1] == 'L': 
                winningstreak += 1 
        else:
            losses += 1
            curloss += 1
            if i == n-1 or s[i-1] == 'W':
                losingstreak.append(curloss)
                curloss = 0
    if k >= losses:
        print(2*n-1)
        continue
    if wins == 0:
        if k == 0:
            print(0)
            continue
        else:
            print(2*k-1)
            continue
    if s[0] == 'L':
        losingstreak[0] = 1e9
    if s[n-1] == 'L':
        losingstreak[len(losingstreak)-1] = 1e9
    losingstreak.sort()
    wins += k 
    for i in range(len(losingstreak)):
        if k < losingstreak[i]:
            break
        else:
            winningstreak -= 1 
            k -= losingstreak[i]
    print(2*wins - winningstreak)