r=range;_,*s=open(0);m=9e9
h,w,k=map(int,_.split())
for i in r(1<<h-1):
 t=[j-1for j in r(h)if i>>j&1]+[h];l=len(t);v=-1;c=[0]*l
 for i in r(w):
  b=f=g=0;u=[]
  for j in r(l):d,b=sum(s[j][i]>"0"for j in r(b,t[j])),t[j];u+=d,;g|=d>k;c[j]+=d;f|=c[j]>k
  v+=f
  if f:c=u
 if not g:m=min(m,v+l)
print(m)