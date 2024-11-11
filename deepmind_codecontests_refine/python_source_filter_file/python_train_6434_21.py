n, m = map(int, input().split())
L = [0] * m
R = [0] * m
for i in range(m):
    L[i], R[i] = list(map(int, input().split()))
print(min(R) - max(L) + 1)
