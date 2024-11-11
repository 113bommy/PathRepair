import sys

n = int(input())
a = list(map(int, input().split()))
ans1, ans2 = 0, 0
for i, x in enumerate(a):
    ans1 += abs(i*2+1 - x)
    ans2 += abs((i+1)*2 - x)

print(min(ans1, ans2))
