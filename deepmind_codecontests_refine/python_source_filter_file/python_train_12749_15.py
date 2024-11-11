n,k=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
m=max(l[0],k-l[-1])
for i in range(n-1):
  m=max(m,l[i+1]-l[i])
print(m*1./2)
  
