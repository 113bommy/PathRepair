import math

t = int(input())
for _ in range(t):
    n = int(input())
    print(n)
    ans = []
    for i in range(1, n+1):
        ans.append(i)
    print(*ans)