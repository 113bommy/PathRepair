#!/usr/bin/env python3
N, M = map(int, input().split())
AB = [list(map(int, input().split())) for i in range(N)]

AB.sort()

ans = 0
for i, j in AB:
	ans += i * min(M, j)
	M -= min(M, j)

print(ans)
