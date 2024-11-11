y,k,n=map(int,input().split())
a=[]
x=k-(y%k)
for i in range(x,n-y+1,k):
    print(i)
if(x<=n-y+1):
    print(-1)