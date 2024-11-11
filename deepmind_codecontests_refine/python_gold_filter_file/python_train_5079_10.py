n,d,a=list(map(int,input().split()))
e=[]
for i in range(n):
  inp=list(map(int,input().split()))
  inp[1]=(inp[1]-1)//a+1
  e.append(inp)
e.sort()
sd=[0 for i in range(n)]
s=0
mx=0
i=0
j=0
while True:
  while e[i][1]+s<=mx:
    i+=1
    if i>=n:
      break
    s+=sd[i]
  while i<n and j<n and e[j][0]<=e[i][0]+2*d:
    j+=1
  if j<n:
      sd[j]+=e[i][1]+s-mx
      mx=e[i][1]+s
  else:
    if i>=n:
      break
    mx=e[i][1]+s
    
print(mx)