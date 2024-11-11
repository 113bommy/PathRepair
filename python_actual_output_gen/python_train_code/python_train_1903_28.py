k,n=map(int,input().split())
a=list(map(int,input().split()))
a.append(k+a[0])
 
for i in range(1,n):
  l=max(a[i]-a[i-1])
 
print(k-l)