x, a, b = map(int, input().split())
print("A" if abs(a-x)<(b-x) else "B")