import sys
sys.setrecursionimit(200000)
n,l=map(int,input().split())
r=list(map(int,input().split()))
last=0;tiepoint=0
for i in range(n-1):
  if r[i]+r[i+1]>last:
    last=r[i]+r[i+1]
    tiepoint=i
if last>=l:
  print("Possible")
  for i in range(tiepoint-1):
    print(i+1)
  for i in range(tiepoint+1,n)[::-1]:
      print(i+1)
  print(tiepoint+1)
else:print("Impossible")
