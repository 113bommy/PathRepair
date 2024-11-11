n=int(input())
ans=0
if n%2==1:
  print(ans)
else:
  i=10
  while n>i:
    ans+=n//i
    i*=5
print(ans)