h,*s=open(0)
h,w,k,*m=map(int,h.split())
b=w
while b:
 b-=1;r=0;t=j=w;d=[0]*h
 while j:
  i=c=0;j-=1
  while h-i:
   d[c]+=s[i][j]>'0';c+=b>>i&1;i+=1
   if max(d)>k:d=[0]*h;r+=1;t,j=j,j+(t<j);i=h
 m+=r+c,
print(min(m))