a=int(input())
b=list(map(int,input().split()))
ans=0
for i in  range(0,a,2):
  if b[i]%2==1:
    ans+=1
print(ans)