n,*l=map(int,open(0).read().split())
c,*l=[0]*9
for i in l:
  if i<3200: l[i//400]=1
  else: c+=1
print(max(1,sum(l)),sum(l)+c)