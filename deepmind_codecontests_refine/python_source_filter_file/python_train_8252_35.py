import math

t = int(input())
for _ in range(t):
    n = int(input())
    print(n-1)
    ans = []
    for i in range(n-1, 0, -1):
        ans.append(i)
    print(*ans)