n=int(input())
for i in range(n):
  c=0
  s=int(input())
  k=list(map(int,input().split()))
  k=sorted(k)
  for j in range(1,s):
    if k[i-1]-k[i]==1:
      c+=1
  if c>=1:
    print('1')
  else:
    print('2')
  
