a, b = map(int, input().split())
print((a+b)//2 if not (a+b)%2 else "IMPOSSIBLE")