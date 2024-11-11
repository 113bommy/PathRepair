n=int(input())
ar=list(map(int,input().split()))
ans=[0]*n
for i in range(20):
    x=sum(list(map(lambda x:(x>>i)&1,ar)))
    for j in range(x):
        ans[j]=1<<i
a=sum(list(map(lambda x:x**2,ans)))
print(a)