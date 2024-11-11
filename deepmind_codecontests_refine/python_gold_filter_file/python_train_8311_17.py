import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**5 + 5)  # 再帰回数の上限！！

n = int(input())
A = [-1] + [int(input()) - 1 for i in range(n-1)]

M = [[] for i in range(n)]
for i in range(1, n):
    M[A[i]].append(i)

# 0-indexedの場合
V = [0] * n

# print(M)

def des(x):
    D = []
    V[x] = 1
    for i in M[x]:
        if V[i] == 0:
            V[i] = 1
            D.append(des(i))
    D.sort(reverse=True)
    # print(x,D)
    for i in range(len(D)):
        D[i] += i+1
    if len(D) == 0:
        ans = 0
    else:
        ans = max(D)
    return ans

print(des(0))