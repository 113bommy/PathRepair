import sys
n,k=map(int,input().split())
c=0
if k*(k-1) < n:
 print('NO')
else:
 print('YES')
 for i in range(k-1):
  for j in range(k):
   c += 1
   if c>k:sys.exit()
   print(j,(j+i+1)%k)
