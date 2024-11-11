from collections import defaultdict
N = int(input())
A = list(map(int, input().split()))
D = defaultdict(int)
ans = 0

for i, x in enumerate(A, 1):
    ans += D[i-x]
    D[x+i] += 1

print(ans, D)