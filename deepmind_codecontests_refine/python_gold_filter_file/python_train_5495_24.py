k,n=map(int,input().split())
a=list(map(int,input().split()))
 
a.append(a[0]+k)
l=0
for i in range(n):
  l=max(l,a[i+1]-a[i])
  
s=k-l

print(s)