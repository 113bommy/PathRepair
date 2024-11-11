a,b,c,d=map(int,input().split())
z=min(a,c,d)
a=a-z
t=min(a,b)
print(a)
print(z*256+t*32)