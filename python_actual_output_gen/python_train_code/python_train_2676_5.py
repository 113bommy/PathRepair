n = int(input())
a = list(map(int,input().split()))
ans =0
temp = float('inf')
for i in range(n-1,-1,-1):
  if a[i]<temp:
    ans+=a[i]
    temp=a[i]
  if a[i]>=temp:
    if temp-1>0:
      ans+=temp-1
      temp =temp-1
    else:
      break
print(ans)
