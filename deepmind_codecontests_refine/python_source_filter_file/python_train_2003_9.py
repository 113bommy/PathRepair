import math
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    current = a[0]
    for i in range(n):
        if a[i] > current:
            current = a[i]
        ans = max(ans, current - a[i])
    if ans == 0:
        print(0)
        continue
    ans = math.ceil(math.log(ans, 2))
    print(ans + 1)