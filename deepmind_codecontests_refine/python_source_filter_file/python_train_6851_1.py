import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

"""
0,0,0,...,0,ev,ev,ev,,,ev,od,od,,,od,ev,ev,,,,ev,0,0,0,0,0
"""

L = int(input())
A = (int(x) for x in sys.stdin.read().split())

# どの状態まで進んだかごとに、最小スコア
a,b,c,d,e = 0,0,0,0,0
for x in A:
    ev_score = 1 if x&1 else (0 if x > 0 else 2)
    od_score = 1-(x&1)
    a1 = a + x
    b1 = min(a,b) + ev_score
    c1 = min(a,b,c) + od_score
    d1 = min(c,d) + ev_score
    e1 = min(c,d,e) + x
    a,b,c,d,e = a1,b1,c1,d1,e1

answer = min(a,b,c,d,e)
print(answer)