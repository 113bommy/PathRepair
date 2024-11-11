# PyPyだとなぜか1ケースだけTLEする。Pythonでは通る。

import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**5 + 5)  # 再帰回数の上限！！

n = int(input())
A = [int(input()) - 1 for i in range(n-1)]

M = [[] for i in range(n)]
for i in range(n-1):
    M[A[i]].append(i+1)

# 0-indexedの場合
V = [0] * n

# print(M)

def des(x):
    D = [0] * len(M[x])
    V[x] = 1
    for ii in range(len(M[x])):
        i = M[x][ii]
        if V[i] == 0:
            V[i] = 1
            D[ii] = des(i)
    if len(D) > 1:
        D.sort(reverse=True)
    # print(x,D)
    ans = 0
    for i in range(len(D)):
        D[i] += i+1
        ans = max(ans, D[i])
    return ans

print(des(0))