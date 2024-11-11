x, a, b = map(int, input().split())
print("A" if abs(x-a)<(x-b) else "B")