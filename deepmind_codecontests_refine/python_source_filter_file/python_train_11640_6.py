n=int(input())
h=list(map(int,input().split()))
ans='Yes'
a[0]-=1
for i in range(n-1):
  if a[i]>a[i+1]:
    ans='No'
  elif a[i+1]>a[i]:
    a[i+1]-=1
print(ans)