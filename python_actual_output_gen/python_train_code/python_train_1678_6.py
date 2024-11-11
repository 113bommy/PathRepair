a,b=map(int,input().split())
k=180/a
ans=0
p=float("INF")
for i in range(1,a-1):
    if abs(i*k-b)<abs(p-b):ans=i;p=abs(i*k-b)
print(1,2,ans+2)