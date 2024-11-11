n=int(input())
a=list(map(int,input().split()))
ans=0
for i in range(n):
  j=a[i]-1
  if a[j]==i+1:
    ans+=1
print(ans//2)