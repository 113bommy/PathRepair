import sys
a,b=map(int,input().split())
b=b+1
l=[0]*(a)
List=list(map(int,input().split()))
i=0
j=1
while l[i]==0 and j<b:
  l[i]+=j
  j+=1
  i=List[i]-1
if j==b:
  print(i+1)
  sys.exit()
roop=j-l[i]
c=(b-j)%roop
for y in range(len(l)):
  if l[y]==c+l[i]:
    print(y+1)
    sys.exit()