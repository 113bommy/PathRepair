_,*s=open(0)
b,q='.'*101,range(101)
for i,s in enumerate(s):
  a=[i]
  for x,y,z,c in zip(b,'.'+s,s,q):a+=min(c+(x=='.'>z),a[-1]+(y=='.'>z)),
  b,q=s,a[1:]
print(a[-2])