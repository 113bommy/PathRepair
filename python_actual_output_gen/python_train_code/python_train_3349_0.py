a,b,c = map(int,input().split())

x = (b*c//a)**0.5
y = (a*b//c)**0.5
z = (a*b//c)**0.5

print(int(4*(x+y+z)))