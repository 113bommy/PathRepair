(n,k),p,c,*a=[[*map(int,t.split())]for t in open(0)]
while n:
 n-=1;s,x,*l=0,n;f=j=k
 while f:x=p[x]-1;s+=c[x];l+=s,;f=x!=n
 for t in l[:k]:j-=1;a+=t+j//len(l)*s*(s>0),
print(max(a))