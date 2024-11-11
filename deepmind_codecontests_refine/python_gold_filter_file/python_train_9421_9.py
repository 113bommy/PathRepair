n=int(input())
x=[];y=[];z=[]
for i in range(1,n*n+1):
    a,b=map(int,input().split())
    if a not in x and b not in y:
        z.append(i)
        x.append(a)
        y.append(b)
print(*z)