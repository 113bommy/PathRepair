#!/usr/bin/env python3
H, W, N = map(int, input().split())
sr, sc = map(lambda x: int(x) - 1, input().split())
S = input()
T = input()
l, r = 0, W
u, d = 0, H
for i in range(N)[::-1]:
    if T[i] == 'L': r = min(W, r + 1)
    if T[i] == 'R': l = max(0, l - 1)
    if T[i] == 'U': d = min(H, d + 1)
    if T[i] == 'D': u = max(0, l - 1)
    if S[i] == 'L': l += 1
    if S[i] == 'R': r -= 1
    if S[i] == 'U': u += 1
    if S[i] == 'D': d -= 1
    if l == r or u == d: 
        print("NO")
        exit()

print(("NO", "YES")[l <= sc < r and u <= sr < d])

