n=int(input())
a=[0]
for i in range(40):
  if n&(1<<i):a.append(i)
print(a)
ans=[]
j=100
for i in range(len(a)-1):
  for _ in range(a[i+1]-a[i]):
    ans.append(j)
    j-=1
  ans.append(i+1)
ans=ans[:-1]
ans=[50]+[100-i for i in range(a[-1])]+[i+1 for i in range(len(a)-2)][::-1]+ans+[50]
print(len(ans))
print(*ans)