n=int(input())
x=[];y=[]
for i in range(1,n*n+1):
    a,b=map(int,input().split())
    if a not in x and b not in x:
        y.append(i)
        x.append(a)
        x.append(b)
print(*y)