n, k = map(int, input().split())
a, b = divmod(n, 2 * k + 1)

print(a + (b > 0))
print(*range((b // 2 if b else k) + 1, n + 1, 2 * k + 1))