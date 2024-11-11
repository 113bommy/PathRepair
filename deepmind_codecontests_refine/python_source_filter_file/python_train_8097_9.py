# -*- coding: utf-8 -*-

#############
# Libraries #
#############

import sys
input = sys.stdin.readline

import math
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
a = inputIL()
b = inputIL()

difa = [0]*N
difb = [0]*N
for i in range(N-1):
  difa[i] = a[i]^a[i+1]
  difb[i] = b[i]^b[i+1]
difa[N-1] = a[0]^a[N-1]
difb[N-1] = b[0]^b[N-1]

if set(difa) != set(dib):
  exit()

memo = []
for i in range(N):
  j = 0
  while difa[(i+j)%N] == difb[j%N]:
    j += 1
    if j == N:
      print(i,a[i]^b[0])
      memo.append(i)
      break
  if len(memo) == 2:
    break

if len(memo) == 2:
  d = memo[1]-memo[0]
  k = memo[1]+d
  while k < N:
    print(k,a[k]^b[0])
    k += d