n, a = map(int, input().split())
print(((n - a) // 2 + 1) if a % 2 == 0 else ((a + 1) // 2))
