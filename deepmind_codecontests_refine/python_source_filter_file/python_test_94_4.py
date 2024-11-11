#!/usr/bin/env python3

import sys

input = iter(sys.stdin.read().splitlines()).__next__

def solve(n, k, A):
   ret = 0
   remK = k + 1
   for i in range(n-1):
      t = min((10 ** (A[i+1] - A[i])) - 1, remK)
      remK -= t
      assert remK >= 0 
      ret += t * (10 ** i)
      if remK == 0:
         return ret

#  print('remK=%d' % (remK), file=sys.stderr)

   ret += remK * (10 ** A[-1])

   return ret


TC = int(input())
for tc in range(TC):
   n, k = map(int, input().split())
   A = list(map(int, input().split()))

   res = solve(n, k, A)
   print(res)

