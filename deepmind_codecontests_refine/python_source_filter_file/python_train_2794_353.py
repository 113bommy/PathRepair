x, a, b = map(int, input().split())
print("a") if abs(a - x) < abs(b - x) else print("b")