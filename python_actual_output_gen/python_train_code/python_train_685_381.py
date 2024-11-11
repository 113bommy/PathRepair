n, k = map(int, input().split())

print(min(n % k, n % abs(n - k)))