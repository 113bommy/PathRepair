import math
from collections import defaultdict

#
t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    ind = -1
    lis = []
    for i in range(n):
        if s[i] == "A":
            lis.append(i)
    ans = 0
    for i in range(len(lis)-1):
        ans = max(ans, lis[i+1] - lis[i]-1)
    if len(lis) > 0:
        ans = max(ans, n-1 - lis[-1])
    print(ans)