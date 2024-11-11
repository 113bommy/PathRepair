n=int(input())
a=list(map(int,input().split()))
a=sorted(a)
ans=a[0]
for i in range(1,n):
  ans=(ans+a[i])/2
print(ans)