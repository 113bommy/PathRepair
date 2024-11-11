a,b,c,d = map(int, input().split())

g = a*b
others = b*c - a*c + a*d

print(g/others)