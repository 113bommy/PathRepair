n=int(input())
a=list(map(int,input().split()))
ans="APPROVED"
for i in range(n):
  if a[i]%2==0 and a[i]%3!=0 and a[i]%5!=0:
    ans="DENIED"
print(ans)