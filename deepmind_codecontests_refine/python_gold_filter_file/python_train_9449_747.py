a,b,c,d=map(int,input().split())

u=max(a*c,a*d)
v=max(b*c,b*d)

print(max(u,v))