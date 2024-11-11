import os,io
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
n=int(input())
a=list(map(int,input().split()))
ans=[]
if a[n-1]==1:
  parity=1
else:
  parity=0
for i in range(n-1):
  if parity%2==0:
    for j in range(n):
      if a[j]==i+1 and j!=i:
        ans.append([])
        for k in range(i):
          ans[-1].append(str(1))
        ans[-1].append(str(j-i+1))
        if n-j-1>0:
          ans[-1].append(str(n-j-1))
        ans[-1].reverse()
        t=len(ans[-1])
        ans[-1].append(str(t))
        ans[-1].reverse()
        b=[]
        for k in range(j+1,n):
          b.append(a[k])
        for k in range(i,j+1):
          b.append(a[k])
        for k in range(i-1,-1,-1):
          b.append(k+1)
        a=b.copy()
        parity+=1
        break
  else:
    for j in range(n):
      if a[j]==i+1 and j!=n-i-1:
        ans.append([])
        if j>0:
          ans[-1].append(str(j))
        if n-j-1>0:
          ans[-1].append(str(n-j-i))
        for k in range(i):
          ans[-1].append(str(1))
        ans[-1].reverse()
        t=len(ans[-1])
        ans[-1].append(str(t))
        ans[-1].reverse()
        b=[]
        for k in range(i):
          b.append(k+1)
        for k in range(j,n-i):
          b.append(a[k])
        for k in range(j):
          b.append(a[k])
        a=b.copy()
        parity+=1
        break
if a[0]!=1:
  ans.append([str(n)])
  for i in range(n):
    ans[-1].append(str(1))
print(len(ans))
for i in ans:
  print(' '.join(i))
  