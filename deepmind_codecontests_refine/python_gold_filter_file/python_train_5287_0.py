from collections import defaultdict
N = int(input())
A = list(map(int, input().split()))
d = defaultdict(int)
ans = 0
for i, x in enumerate(A, 1):
    ans += d[i-x]
    d[x+i] += 1
print(ans)
