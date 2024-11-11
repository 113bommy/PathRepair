a, b, n = map(int, input().split())
f = max(n, b-1)

print((a*f)//b -a*(f//b))