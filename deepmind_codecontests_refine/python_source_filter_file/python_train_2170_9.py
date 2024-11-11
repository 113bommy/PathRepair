n=int(input())
a=list(map(int,input().split()))
cnt=0
for i range(n):
  if a[i]%2==0:
    cnt+=1
ans=(3*n)-2*cnt
print(ans)