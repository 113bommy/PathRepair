n,k=map(int,input().split())
k-=1
x=list(map(int,input().split()))
print(min(min(abs(x[i],x[i+k]))+abs(x[i]-x[i+k])for i in range(n-k)))