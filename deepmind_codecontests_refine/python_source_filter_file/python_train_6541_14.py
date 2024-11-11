import sys
input = sys.stdin.readline

N, C = (int(i) for i in input().split())

pp = [[0] * 100000 for i in range(C)]

for i in range(N):
    s, t, c = (int(i) for i in input().split())
    for j in range(s, t+1):
        pp[c-1][j] = 1

res = 0
for i in range(100000):
    cc = 0
    for j in range(C):
        if pp[j][i]:
            cc += 1
    res = max(res, cc)

print(res)
