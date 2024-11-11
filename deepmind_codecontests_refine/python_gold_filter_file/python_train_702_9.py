from collections import Counter

N = int(input())

A = list(map(int, input().split()))
c = Counter(A)
S = sum(A)

Q = int(input())
for _ in range(Q):
    x, y = map(int, input().split())
    S += (c[x]*(y-x))
    print(S)
    c[y] += c[x]
    c[x] = 0