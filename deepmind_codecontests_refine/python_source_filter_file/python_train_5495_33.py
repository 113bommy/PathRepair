k,n=map(int,input.split())
l=list(map(int,input.split()))
v=[k-l[-1]+l[0]]
for i in range(n-1):
  v.append(l[i+1]-l[i])
v.sort()
print(k-v[-1])