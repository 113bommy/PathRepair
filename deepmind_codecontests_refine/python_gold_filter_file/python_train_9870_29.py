a, b = map(int, input().split())
print(b if a >= 13 else b//2 if 6 <= a else 0)
