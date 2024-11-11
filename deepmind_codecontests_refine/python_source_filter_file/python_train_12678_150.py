n, a, b = map(int, input().split())
l, m = divmod(n, a+b)
print(l*a+m)
