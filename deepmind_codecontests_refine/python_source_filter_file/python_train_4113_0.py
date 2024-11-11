n=int(input())
l=[]
for i in range(2,2*n+1):
  if i==2: s=[0,int(input())]
  else: s=[0]+list(map(int,input().split()))
  for j in range(1,i):
    l+=[(s[j],i,j)]
l=sorted(l)
print(l)
s=set()
k=[0]*(2*n+1)
for x in l[::-1]:
  if x[1] in s or x[2] in s: continue
  s|={x[1],x[2]}
  k[x[1]]=x[2]
  k[x[2]]=x[1]
print(' '.join(map(str,k[1:])))
