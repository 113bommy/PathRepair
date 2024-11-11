n,k,l,c,d,p,nl,np=[int(i) for i in input().split()]
x=(k*l)//nl
y=c*d
z=p*np
res=min(x,y,z)
print(res//n)