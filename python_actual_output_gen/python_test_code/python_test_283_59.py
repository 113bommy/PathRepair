x, a, b = map(int, input().split())
print("delicious" if a + b >= x else "safe" if x >= a else "dangerous")