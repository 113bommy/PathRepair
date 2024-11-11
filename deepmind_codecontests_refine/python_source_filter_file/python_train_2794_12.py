x, a, b = list(map(int, input().split()))
print("a" if abs(x-a) < abs(x-b) else "b")
