n=int(input())
a=list(map(int,input().split()))
ans=10**9
x=sum(a)
b=0
for i in a[:-1]:
   b+=i
   x-=i
   ans=min(ans,abs(x-b))
print(ans)