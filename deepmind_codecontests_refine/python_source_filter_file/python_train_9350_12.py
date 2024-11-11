N,K=map(int,input().split())
a=list(map(int,input().split()))
b=[]
for i in range(N-K+1):
    b.append(min(abs(a[i])+abs(a[i+K-1]-a[i]),abs(a[i+K-1])+abs(a[i]-a[i+K-1]))
print(min(b))
