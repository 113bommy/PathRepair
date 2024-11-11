import time
n, m = map(int, input().split())
numbers = list(map(int, input().split()))
costs = [0,2,5,5,4,5,6,3,7,6]
f = [-1]*10010
f[0] = 0
for i in range(1, n+1):
    for x in numbers:
        if i-costs[x] >= 0:
            f[i] = max(f[i], f[i-costs[x]]*10+x)
print(f)