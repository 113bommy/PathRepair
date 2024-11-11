n,k = map(int,input().split())
a = list(map(int,input().split()))
l = [1]
for i in range(n):  
    l.append(a[l[i]-1])
    
p = l.index(l[-1])
if k<=n:
  print(l[k])
  exit()
  
x = (k-n+1)%(n-p)
if x==0:
  print(l[n-1])
else:
  print(l[x+p-1])
