import math

n = int(input())
a = list(map(int, input().split()))

c1 = math.ceil(a[-1]**(1/(n-1)))
c2 = math.floor(a[-1]**(1/(n-1)))

ans1 = 0
ans2 = 0

for i in range(len(a)):
    t = c1**i - a[i]
    ans1 += abs(t)

    t = c2**i - a[i]
    ans2 += abs(t)

print(min(ans1, ans2))
    
