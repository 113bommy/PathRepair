from itertools import product

N, M, K = map(int, input().split())
S = set()

for i, j in product(range(N+1), range(M+1)):
    S.add((M-j)*i + (N-i)*j)

print("Yes" if K in S else "No")