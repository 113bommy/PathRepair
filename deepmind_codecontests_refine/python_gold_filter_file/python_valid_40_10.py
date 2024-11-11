import sys
import math

#def get_ints(): 
#  return map(int, sys.stdin.readline().strip().split())
def inpu():
  return sys.stdin.readline()
 
#lets = 'abcdefghijklmnopqrstuvwxyz'
#letts = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
#key = {lets[i]:i for i in range(26)}
 
#prime  = [1,11,101,1009,10007,100003,1000003,10000019,100000007]
#prime2 = [2,13,103,1013,10009,100019,1000033,10000169,100000049]
 
#big = int(1e9 + 7)

#def gcd(a, b):
#  while b:
#    a, b = b, a%b
#  return a

"""
primes = []

def primes_gen(n):
  for i in range(2,1+int(n**0.5)):
    g = True
    for j in primes:
      if i % j == 0:
        g = False
        break
    if g:
      primes.append(i)

primes_gen(1e9 + 10)
"""

T = int(input())

for t in range(T):
  n = int(input())
  #n,m = map(int,input().split())
  a = list(map(int,input().split()))  
  b = list(map(int,input().split()))  
  #a = input()
  #a = list(input())
  done = False

  sa = sum(a) - a[0]
  #sb = sum(b) - b[-1]

  ans = sa

  sb = 0
  for i in range(1,n):
    sa -= a[i]
    sb += b[i-1]
    ans = min(ans,max(sa,sb))
  
  print(ans)