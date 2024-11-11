n, p = map(int, input().split())
print(p if n > 10 else p + 100 * (10 - n))