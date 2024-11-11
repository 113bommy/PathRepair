n, a, b = map(int, input().split())
p = max(a, b)
q = max((a+b)-n, 0)

print(p, q)