h,a,*m=open(0)
h,w,k,a,b,f,g=map(int,(h+a).split())
I=h*w
d=[I]*I
a=~w+a*w+b
d[a]=1
q=[a]
for s in q:
 for y,x in(1,0),(-1,0),(0,1),(0,-1):
  for z in range(k):
   i,j=s//w+y*~z,s%w+x*~z;t=i*w+j
   if(h>i>-1<j<w)-1or'.'<m[i][j]or d[t]<d[s]:break
   if d[t]==I:q+=t,;d[t]=d[s]+1
print(d[~w+f*w+g]%I-1)