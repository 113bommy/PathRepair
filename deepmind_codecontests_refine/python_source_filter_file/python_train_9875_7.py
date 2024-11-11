n=int(input())
a=list(map(int,input().split()))
b=[[a[i],i] for i in range(n)]+[[0,n-1]]
b.sort(reverse=1)
ans=[0]*n
j=n-1
for i in range(n):
  j=min(b[i][1],j)
  c=b[i][0]-b[i+1][0]
  if c!=0:ans[j]=c*(i+1)
print(*ans)