# 146B

from sys import stdin

__author__ = 'artyom'


def lucky_mask(x):
  return ''.join([s for s in str(x) if s == '4' or s == '7'])


a, b = stdin.readline().strip().split()
a = int(a) + 1

while lucky_mask(a) != b:
  a += 1
print(a)