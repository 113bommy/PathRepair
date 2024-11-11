n,m=map(int,input().split())
a=list(map(int,input().split()))
b=[]
o=[]
for i in a:
  if i%2:o.append(i)
  else:b.append(i)
if len(o)>2:print("Impossible");exit()
if len(o)==1:b=o+b
elif len(o)==2:b=[o[0]]+b+[o[1]]
ans=[]
for i in range(len(b)):
  if i==0:ans.append(b[i]-1)
  elif i==len(b)-1:ans.append(b[i]+1)
  else:ans.append(b[i])
anss=[]
for i in ans:
  if i!=0:anss.append(i)
if sum(anss)!=n:anss.append(n-sum(anss))
print(*a)
print(len(anss))
print(*anss)