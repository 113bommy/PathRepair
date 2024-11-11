import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

from fractions import gcd
from functools import reduce

MOD = 10**9 + 7

N,*A = map(int,read().split())
A.sort()

"""
安い鳥から追加していく。(サイクルの個数 -> 美しさ)が多項式倍で遷移する。
Gaussの補題より、最大個数かけるだけ
"""

answer = reduce(lambda x,y: x*y%MOD, (gcd(i,x) for i,x in enumerate(A)))
print(answer)