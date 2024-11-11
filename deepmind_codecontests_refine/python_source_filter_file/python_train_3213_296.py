a, b, x = map(int, input().split())
print(b // x - int((a - 0.1) // x))