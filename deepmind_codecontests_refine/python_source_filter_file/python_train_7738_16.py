def checkprime(x):
  prime=True
  for i in range(2,int(pow(x,1/2))+1):
    if x%i==0: prime=False
  return True if prime==True else False
pnum=[]
cnt=0
n,k=map(int, input().split())
for i in range(2,n+1):
  if checkprime(i):
    pnum.append(i)
i=4
while cnt<k and len(pnum)>=5:
  for j in range(i-1):
    if pnum[j]+pnum[j+1]+1==pnum[i]:
      cnt+=1
      break
  if cnt==k:
    n=0
    break
  if i+1==len(pnum): break
  else: i+=1
if n==0: print("YES")
else: print("NO")
