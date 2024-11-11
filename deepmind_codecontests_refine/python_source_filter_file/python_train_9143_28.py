a, b, c, d = map(int, input().split())
print(min(0, min(b,d) - max(a,c)))