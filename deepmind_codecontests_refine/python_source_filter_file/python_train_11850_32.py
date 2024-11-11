n,m=map(int,input().split())
ans=1
for i in range(2,int(m**.5)+1):
  if m%i==0:
    if i*n<=m and ans<i:
      ans=i
    if n<=i and ans<m//i:
      ans=m//i
print(ans)