from collections import defaultdict, deque, Counter
from sys import stdin, stdout
import sys
from heapq import heappush, heappop
import math
import io
import os
import math
import bisect



#?############################################################


def ncr(n, r, p):
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den, p - 2, p)) % p


#?############################################################

def primeFactors(n):
    l = []
    while n % 2 == 0:
        l.append(2)
        n = n // 2
    for i in range(3, int(math.sqrt(n))+1, 2):
        while n % i == 0:
            l.append(int(i))
            n = n // i
    if n > 2:
        l.append(n)
    return list(set(l))


#?############################################################



def mapin():
    return map(int, input().split())

#?############################################################



n, m = mapin()
r, c = mapin()
x, y = mapin()
dp = []
for i in range(n):
    s = input()
    dp.append(s)

ans = [[0 for i in range(2005)] for j in range(2005)]
q = deque()
q.append([r-1, c-1, x, y])
while(len(q)):
    temp = q[0]
    q.popleft()
    
    if(temp[0]<0 or temp[0]>=n or temp[1]<0 or temp[1]>=m):
        continue
    if(ans[temp[0]][temp[1]] ==1):
        continue
    if(dp[temp[0]][temp[1]] == '*'):
        continue
    if(temp[2]<0 or temp[3]<0):
        continue
    ans[temp[0]][temp[1]] = 1
    q.append([temp[0]+1, temp[1], temp[2], temp[3]])
    q.append([temp[0]-1, temp[1], temp[2], temp[3]])
    q.append([temp[0], temp[1]+1, temp[2], temp[3]-1])
    q.append([temp[0], temp[1]-1, temp[2]-1, temp[3]])


out = 0
for i in ans:
    out+=sum(i)
 
print(out)
