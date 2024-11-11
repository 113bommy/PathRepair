x, y, z = map(int,input().split())
c = int(((y*z)/x)**0.5)
b = y/c
a = x/b
s = a+b+c
print(int(4*s))