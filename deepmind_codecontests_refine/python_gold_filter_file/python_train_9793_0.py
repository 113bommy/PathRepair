a, b = map(int, input().split())
print(abs(a) // abs(b) if a*b >= 0 else -(abs(a) // abs(b)))
