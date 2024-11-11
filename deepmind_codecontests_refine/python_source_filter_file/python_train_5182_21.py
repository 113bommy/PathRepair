(n,k),p,c=[[*map(int,t.split())]for t in open(0)]
a=-1e9
for i in range(n):
 s=t=f=m=0;x,*l=i,
 while~f:x=p[x]-1;l+=c[x],;s+=c[x];m+=1;f-=x==i
 for j in range(min(m,k)):t+=l[j];a=max(a,t+(~j+k)//m*s*(s>0))
print(a)