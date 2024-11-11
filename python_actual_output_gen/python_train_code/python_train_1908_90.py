from itertools import product

N, M, K = map(int, input().split())
S = set()

for i, j in product(range(N), range(M)):
    S.add((M-j)*i + (N-i)*j)

print("Yes" if K in S else "No")