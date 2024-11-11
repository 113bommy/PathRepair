h,*s=open(0)
h,w,k=map(int,h.split())
m=b=w
while b:
 b-=1;r=t=j=-1;d=[0]*h
 while~j+w:
  j+=1;i=c=0
  while h-i:
   d[c]+=s[i][j]>'0'
   if d[c]>k:d=[0]*h;f=t<j;r-=h*w*~-f-1;t=j;j-=f;break
   c+=b>>i&1;i+=1
 m=min(m,r-~c)
print(m)