n=int(input())
l=[0]*9
for i in map(int,input().split()):
  i//=400
  if i<8: l[i]=1
  else: l[8]+=1
print(sum(l[:8]),sum(l))