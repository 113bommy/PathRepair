#!/usr/bin/python3
# -*- coding:utf-8 -*-

def p(n, k, mod):
  x = 1
  for ik in range(k):
    x *= (n - ik)
    x %= mod
  return x

MAX = 10 ** 9 + 7
def main():
  n, m = map(int, input().strip().split())
  s = 0
  nck = 1
  mpk = 1
  mkpnk = p(m, n, MAX)
  for k in range(0, n+1):
    if 0 < k <= n:
      nck *= (n - (k-1)) * pow(k, MAX-2, MAX) 
      nck %= MAX
    if 0 < k <= m:
      mpk *= (m - (k-1))
      mpk %= MAX
    if 0 < k <= n:
      mkpnk *= pow(m - (k - 1), MAX-2, MAX) 
      mkpnk %= MAX
    s += nck * ( (-1) ** k) * mpk * (mkpnk) ** 2
    s %= MAX
  print(s)
  

if __name__=='__main__':
  main()

