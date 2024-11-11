n=int(input())
for i in range(n):
  c=0
  s=int(input())
  k=list(map(int,input().split()))
  k=sorted(k)
  for j in range(1,s):
    if abs(k[j-1]-k[j])==1:
      c+=1
  if c>=1:
    print('2')
  else:
    print('1')
  
