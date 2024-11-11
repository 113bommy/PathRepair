n, a = map(int, input().split())
print(((n - a) // 2 + 1) if a % 2 else ((a + 1) // 2))