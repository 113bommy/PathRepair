n,k,*a=map(int,open(0).read().split())
for _ in range(k):
 b=[0]*n
 for i,q in enumerate(a):
  b[max(0,i-q)]+=1
  if i+q+1<n:b[i+q+1]-=1
  for i in range(1,n):b[i]+=b[i-1]
  if b==a:break
  a=b[:]
print(*a)
