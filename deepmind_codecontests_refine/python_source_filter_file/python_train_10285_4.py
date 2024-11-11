# -*- coding: utf-8 -*-

#############
# Libraries #
#############

import sys
input = sys.stdin.readline

import math
from collections import deque
from fractions import gcd
from functools import lru_cache

#############
# Constants #
#############

MOD = 10**9 +7
INF = float('inf')

#############
# Functions #
#############

######INPUT######
def inputI(): return int(input().strip())
def inputS(): return input().strip()
def inputIL(): return list(map(int,input().split()))
def inputSL(): return list(map(str,input().split()))
def inputILs(n): return list(int(input()) for _ in range(n))
def inputSLs(n): return list(input().strip() for _ in range(n))
def inputILL(n): return [list(map(int, input().split())) for _ in range(n)]
def inputSLL(n): return [list(map(str, input().split())) for _ in range(n)]

#####Inverse#####
def inv(n): return pow(n, MOD-2, MOD)

######Combination######
kaijo_memo = []
def kaijo(n):
  if(len(kaijo_memo) > n):
    return kaijo_memo[n]
  if(len(kaijo_memo) == 0):
    kaijo_memo.append(1)
  while(len(kaijo_memo) <= n):
    kaijo_memo.append(kaijo_memo[-1] * len(kaijo_memo) % MOD)
  return kaijo_memo[n]

gyaku_kaijo_memo = []
def gyaku_kaijo(n):
  if(len(gyaku_kaijo_memo) > n):
    return gyaku_kaijo_memo[n]
  if(len(gyaku_kaijo_memo) == 0):
    gyaku_kaijo_memo.append(1)
  while(len(gyaku_kaijo_memo) <= n):
    gyaku_kaijo_memo.append(gyaku_kaijo_memo[-1] * pow(len(gyaku_kaijo_memo),MOD-2,MOD) % MOD)
  return gyaku_kaijo_memo[n]

def nCr(n,r):
  if(n == r):
    return 1
  if(n < r or r < 0):
    return 0
  ret = 1
  ret = ret * kaijo(n) % MOD
  ret = ret * gyaku_kaijo(r) % MOD
  ret = ret * gyaku_kaijo(n-r) % MOD
  return ret

######Factorization######
def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])
    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])
    return arr

#####LCM#####
def lcm(a, b):
    return a * b // gcd (a, b)

#############
# Main Code #
#############

N = inputI()
l = inputILL(N-1)

dic = dict([(i,[]) for i in range(1,N+1)])

for i in l:
  dic[i[0]].append(i[1])
  dic[i[1]].append(i[0])


d = [[INF,i] for i in range(N+1)]
d[1][0] = 0
q = deque([1])

while q:
  x = q.popleft()
  nd = d[x][0]+1
  for nx in dic[x]:
    if nd < d[nx][0]:
      d[nx][0] = nd
      q.append(nx)


d_ = sorted(d[1:],reverse=True)
n = [1 for _ in range(N+1)]

for item in d_:
  depth = item[0]
  i = item[1]
  for j in dic[i]:
    if d[j][0] == depth+1:
      n[i] += n[j]

print(n)
ans = (pow(2,N,MOD)-N*pow(2,N-1,MOD)-1)%MOD
for i in range(2,N+1):
  ans = (ans + (pow(2,n[i],MOD)-1) * (pow(2,N-n[i],MOD)-1)) % MOD

print((ans*inv(pow(2,N,MOD)))%MOD)