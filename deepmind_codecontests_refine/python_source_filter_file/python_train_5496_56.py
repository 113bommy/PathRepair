import sys
input = sys.stdin.readline

m = int(input())
sum1 = 0
sumc = 0
ans = 0

for i in range(m):
    d,c = map(int,input().split())
    sum1 += d * c
    sumc += c

ans += sumc + sum1 // 9 - 1

print(ans)
