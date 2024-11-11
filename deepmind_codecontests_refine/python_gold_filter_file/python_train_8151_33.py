n,k,l,c,d,p,nl,np=map(int,input().split())
k*=l
k//=nl
c*=d
p//=np
print(min(k,c,p)//n)