a,b,c,d = map(int, input().split())
x = max(a*c, a*d, b*c, b*d)
print(x)