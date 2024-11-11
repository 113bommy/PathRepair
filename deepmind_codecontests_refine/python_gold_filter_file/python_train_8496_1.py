n=int(input())
x,y=map(int,input().split())
z=x
for i in range(n-1):
    x,y=map(int,input().split())
    if (z+1)<=(x):
        z=x
    else:
        z=(x+(((z-x)//y)+1)*y)
print(z)