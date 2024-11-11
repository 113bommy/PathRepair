# 311A

from sys import stdin

__author__ = 'artyom'

n, k = map(int, stdin.readline().strip().split())
if n * (n - 1) / 2 <= k:
  print('no solution')
  exit()

for i in range(n):
  print(i, i)