(n,m),*l=[list(map(int,s.split()))for s in open(0)];d=[0]*2+[9e99]*n
for i in range(n*2):
 for a,b,c in l:
  if d[b]>d[a]-c:d[b]=[d[a]-c,-9e99][i>n]
 if i==n:x=d[n]
print([-x,'inf'][d[n]!=x])