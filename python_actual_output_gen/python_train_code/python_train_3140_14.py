N, T = map(int, input().split())

A = list(map(int, input().split()))
m = max(A)

print(max(0, m - 1 - (T - 1)))
