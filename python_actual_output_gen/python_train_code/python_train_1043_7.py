import sys
sys.setrecursionlimit(10**9)

N= int(input())

G = [[] for i in range(N)]

for i in range(N-1):
    a, b = map(int, input().split())
    G[a-1].append([b-1, i])

ans = [None]*(N-1)

def func(prt, col):
    cnt = 1
    for cld, org in G[prt]:
        if cnt==org:
            cnt += 1
        ans[org] = cnt
        func(cld, cnt)
        cnt += 1

func(0, 0)

print(max(ans))
for i in range(N-1):
    print(ans[i])