n,m=map(int,input().split())
x=list(map(int,input().split()))
t=x[0]
for i in range(0,m-1):
    if x[i]<=x[i+1]:
        t+=(x[i+1]-x[i])
    elif x[i]>x[i+1]:
        t+=(n-x[i]+x[i+1])
print(t-1)