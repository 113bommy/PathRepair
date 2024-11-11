n, k = map(int, input().split())
A = sum(list(map(int, input().split())))
print(max(2 * n * k - n - 2 * A, 0))