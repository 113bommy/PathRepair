import sys
hom = sys.stdin.readline()[:-1]
away = sys.stdin.readline()[:-1]
numcases = int(sys.stdin.readline())
ht=[0]*100
at=[0]*100

def solve(a):
  p=int(a.split()[2])
  t=int(a.split()[0])
  ah = a.split()[1]
  if ah=='h':
    n = hom
    if ht[p]<=2:
      if a.split()[3]=='y':
        ht[p]+=1
      else:
        ht[p]=2
      if ht[p]==2:
        x =[(t,n,p)]
        return x
  else:
    if at[p]<=2:
      n = away
      if a.split()[3]=='y':
        at[p]+=1
      else:
        at[p]=2
      if at[p]==2:
        x =[(t,n,p)]
        return x
r=[]
for casenum in range(1,numcases+1):
  x =solve(sys.stdin.readline())
  if x!= None:
    r= r+ x
  
for i in list(sorted(r)):
  print (i[1], i[2],i[0])