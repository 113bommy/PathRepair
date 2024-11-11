x,y,z=map(int,input().split())
a,b,c=map(int,input().split())
if (a>=x) and (b+a-x>=y) and (c+b+c-x-y>=z):
    print("YES")
else:
    print("NO")        