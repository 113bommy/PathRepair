a,b,c=map(int, input().split())
d=(b**2-4*a*c)**0.5/2/a
b=-b/2/a
c=sorted((b-d,b+d))
print("{:.9f}\n{:.9f}".format(c[0],c[1]))