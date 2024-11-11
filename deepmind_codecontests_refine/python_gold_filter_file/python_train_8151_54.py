n,k,l,c,d,p,nl,np=map(int,input().split())
a=(k*l)//nl
l=c*d
s=p//np
print(min(a,l,s)//n)