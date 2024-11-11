from sys import exit, setrecursionlimit, stderr
from functools import reduce
from itertools import *
from collections import defaultdict
from bisect import bisect

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

N = read()
S = input()

former = defaultdict(int)
latter = defaultdict(int)

for bits in range(1 << N):
  bs1 = []; rs1 = []; bs2 = []; rs2 = []
  for i in range(N):
    if (1 << i) & bits:
      rs1.append(S[i])
      rs2.append(S[-i])
    else:
      bs1.append(S[i])
      bs2.append(S[-i])
  former["".join(rs1), "".join(bs1)] += 1
  latter["".join(bs2), "".join(rs2)] += 1

ans = 0
for k, v in former.items():
  if k in latter:
    ans += v * latter[k]

print(ans)