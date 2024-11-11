n,k,l,c,d,p,nl,np=map(int,input().split())
q=k*l
q=q//nl
z=p//np
s=c*d
a=min(q,z,s)//n
print(a)