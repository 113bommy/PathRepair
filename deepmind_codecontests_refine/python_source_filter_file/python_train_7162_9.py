import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
N = int(input())
K = 10**5+1
P = [i for i in range(K)]

def par(a):
    if P[a] == a:
        return a
    t = par(P[a])
    P[a] = t
    return t
def cb(a, b):
    P[pa] = pb

X = [[] for _ in range(K)]
Y = [[] for _ in range(K)]
for _ in range(N):
    x, y = map(int, input().split())
    X[x-1].append(y-1)
    Y[y-1].append(x-1)
for i in range(K):
    for j in range(len(Y[i])-1):
        cb(Y[i][j], Y[i][j+1])

M = [[] for _ in range(K)]
for i in range(K):
    M[par(i)].append(i)
ans = -N
for i in range(K):
    S = []
    for j in M[i]:
        for k in X[j]:
            S.append(k)
    S = list(set(S))
    ans += len(S)*len(M[i])
print(ans)
