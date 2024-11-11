n=int(input())
a=list(map(int,input().split()))
ans=s[0]
for i in range(n):
  ans^=s[i]
if ans!=0:
  print('No')
else:
  print('Yes')