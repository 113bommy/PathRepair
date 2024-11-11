k,n=map(int,input().split())
a=list(map(int,input().split()))
a.append(k+a[0])

l=0
for i in range(1,n+1):
  l=max(l,a[i]-a[i-1])
 
print(k-l)