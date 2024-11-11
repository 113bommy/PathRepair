n, k = map(int, input().split())
n %= m
print(min(n, m - n))