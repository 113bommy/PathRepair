a, b, c, k = map(int, input().split())
l = max(0, k - a)
m = max(0, l - b)
print(a - m)
