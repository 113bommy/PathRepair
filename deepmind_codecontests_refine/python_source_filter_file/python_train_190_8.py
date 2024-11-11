x=input()
t=0
for i in range(len(x)-1,-1,-1):
  if x[i]=='T':
    t+=1
  else:
    if t>0:
      t-=1
    else:
      s+=1
print(s+t)