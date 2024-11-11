n,d=map(int,input().split())
c=0
p=d*d
for j in range(n):
    x,y=map(int,input().split())
    if (x**2) + (y**2)==p:
        c=c+1
print(c)
