import sys
import math

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

d = [ y - x for x, y in zip(A, B)]

q = [ x // 2 for x in d if x > 0]
r = [ -x for x in d if x < 0]

if sum(q) > sum(r):
    print("Yes")
else:
    print("No")