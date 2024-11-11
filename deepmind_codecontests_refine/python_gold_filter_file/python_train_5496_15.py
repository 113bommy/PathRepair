import sys
readline = sys.stdin.readline
M = int(readline())
ans = 0
res = 0
for _ in range(M):
    d, c = map(int, readline().split())
    ans += d*c
    res += c

print(-((9-ans)//9) + res - 1)