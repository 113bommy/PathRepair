import sys
from sys import stdin,stdout
n,m,k=map(int,stdin.readline().split(' '))
t22=stdin.readline()#;print(t22,"t2222")
bl=[]
if len(t22.strip())==0:
  bl=[]
else:
  bl=list(map(int,t22.split(' ')))
bd={}
for i in bl:
  bd[i]=1
cost=list(map(int,stdin.readline().split(' ')))
dp=[-1 for i in range(n)]
dp[0]=0

def formdp():
  global dp
  for i in range(1,n):
    if i in bd:
      t1=i
      while dp[t1]==-1:
        t1-=1
      dp[i]=dp[t1]
    else:
      dp[i]=i
    

def get(i):
  #print("\t",i)
  f=1;p=0
  while p+i<n:
    if dp[p+i]==p:
      return -1
    else:
      p=dp[p+i];f+=1
    #print(p,f)
  return f
if True:
  if 0 in bd:
    print(-1)
  else:
    formdp()
    #print(dp)
    minf=[0 for i in range(k+1)]
    for i in range(1,k+1):
      minf[i]=get(i)
    #print(minf)
    ans=-1

    for i in range(1,len(minf)):
      if minf[i]!=-1:
        if ans==-1:
          ans=minf[i]*cost[i-1]
        else:
          ans=min(ans,minf[i]*cost[i-1])
    if ans==-1:
      print(-1)
    else:
      print(ans)
#except Exception as e:
#  print(e)
#print(sys.maxsize)