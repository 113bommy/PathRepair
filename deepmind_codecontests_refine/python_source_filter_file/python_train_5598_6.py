# -*- coding: utf-8 -*-

#############
# Libraries #
#############

import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

import math
#from math import gcd
import bisect
import heapq
from collections import defaultdict
from collections import deque
from collections import Counter
from functools import lru_cache

#############
# Constants #
#############

MOD = 998244353
INF = float('inf')
AZ = "abcdefghijklmnopqrstuvwxyz"

#############
# Functions #
#############

######INPUT######
def I(): return int(input().strip())
def S(): return input().strip()
def IL(): return list(map(int,input().split()))
def SL(): return list(map(str,input().split()))
def ILs(n): return list(int(input()) for _ in range(n))
def SLs(n): return list(input().strip() for _ in range(n))
def ILL(n): return [list(map(int, input().split())) for _ in range(n)]
def SLL(n): return [list(map(str, input().split())) for _ in range(n)]


#####Shorten#####
def DD(arg): return defaultdict(arg)

#####Inverse#####
def inv(n): return pow(n, MOD-2, MOD)

######Combination######
kaijo_memo = []
def kaijo(n):
  if(len(kaijo_memo) > n): return kaijo_memo[n]
  if(len(kaijo_memo) == 0): kaijo_memo.append(1)
  while(len(kaijo_memo) <= n): kaijo_memo.append(kaijo_memo[-1] * len(kaijo_memo) % MOD)
  return kaijo_memo[n]

gyaku_kaijo_memo = []
def gyaku_kaijo(n):
  if(len(gyaku_kaijo_memo) > n): return gyaku_kaijo_memo[n]
  if(len(gyaku_kaijo_memo) == 0): gyaku_kaijo_memo.append(1)
  while(len(gyaku_kaijo_memo) <= n): gyaku_kaijo_memo.append(gyaku_kaijo_memo[-1] * pow(len(gyaku_kaijo_memo),MOD-2,MOD) % MOD)
  return gyaku_kaijo_memo[n]

def nCr(n,r):
  if n == r: return 1
  if n < r or r < 0: return 0
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
  if temp!=1: arr.append([temp, 1])
  if arr==[]: arr.append([n, 1])
  return arr

#####MakeDivisors######
def make_divisors(n):
  divisors = []
  for i in range(1, int(n**0.5)+1):
    if n % i == 0:
      divisors.append(i)
      if i != n // i: 
        divisors.append(n//i)
  return divisors

#####MakePrimes######
def make_primes(N):
  max = int(math.sqrt(N))
  seachList = [i for i in range(2,N+1)]
  primeNum = []
  while seachList[0] <= max:
    primeNum.append(seachList[0])
    tmp = seachList[0]
    seachList = [i for i in seachList if i % tmp != 0]
  primeNum.extend(seachList)
  return primeNum

#####GCD#####
def gcd(a, b):
    while b: a, b = b, a % b
    return a

#####LCM#####
def lcm(a, b):
    return a * b // gcd (a, b)

#####BitCount#####
def count_bit(n):
  count = 0
  while n:
    n &= n-1
    count += 1
  return count

#####ChangeBase#####
def base_10_to_n(X, n):
  if X//n: return base_10_to_n(X//n, n)+[X%n]
  return [X%n]

def base_n_to_10(X, n):
  return sum(int(str(X)[-i-1])*n**i for i in range(len(str(X))))

def base_10_to_n_without_0(X, n):
  X -= 1
  if X//n: return base_10_to_n_without_0(X//n, n)+[X%n]
  return [X%n]

#####IntLog#####
def int_log(n, a):
  count = 0
  while n>=a:
    n //= a
    count += 1
  return count

#############
# Main Code #
#############

N,Q = IL()
base = 10**6

class RUQ:
  def __init__(self, N, default = None):
    self.N0 = 2**(N-1).bit_length()
    self.data = [(-1, default)]*(2*self.N0)
    self.INF = (-1, default)
  # 区間[l, r+1)の値をvに書き換える
  # vは(t, value)という値にする (新しい値ほどtは大きくなる)
  def update(self, l, r, v):
    L = l + self.N0; R = r + self.N0
    while L < R:
      if R & 1:
        R -= 1
        self.data[R-1] = v
      if L & 1:
        self.data[L-1] = v
        L += 1
      L >>= 1; R >>= 1
  # a_iの現在の値を取得
  def _query(self, k):
    k += self.N0-1
    s = self.INF
    while k >= 0:
      if self.data[k]:
        s = max(s, self.data[k])
      k = (k - 1) // 2
    return s
  # これを呼び出す
  def query(self, k):
    temp = self._query(k)[1]
    return temp//(base**2), (temp%(base**2))//base, temp%base
  
ST = RUQ(220000,1*base**2+1*base+N)

ichiga = [0]
for _ in range(N):
  ichiga.append((ichiga[-1]*10+1)%MOD)

ans = ichiga[-1]

for i in range(Q):
  l,r,d = IL()
  p = l
  while p <= r:
    x,f,t = ST.query(p)
    ans -= (ichiga[N-p+1]-ichiga[N-min(t,r)])*x
    ans %= MOD
    p = t+1  
  x,f,t = ST.query(l)
  ST.update(f,l,(i*3,x*base**2+f*base+l-1))
  x,f,t = ST.query(r)
  ST.update(r,t+1,(i*3+1,x*base**2+r*base+t))
  ST.update(l,r+1,(i*3+2,d*base**2+l*base+r))
  ans += (ichiga[N-l+1]-ichiga[N-r])*d
  ans %= MOD
  print(ans)