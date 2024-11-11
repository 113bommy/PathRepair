n=int(input())
a=list(map(int,input().split()))
ans=0
for i in a[1::2]:
  ans+=i%2
print(ans)