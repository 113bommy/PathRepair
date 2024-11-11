n,m=map(int,input().split())
ans=1
for i in range(2,int(m**0.5)+1):
  if m%i==0:
    x=i
    y=m//i
    if m//i>=n and ans<i:
      ans=i
    if m//y>=n and ans<y:
      ans=y
print(ans)