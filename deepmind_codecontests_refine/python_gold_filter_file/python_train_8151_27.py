n,k,l,c,d,p,nl,np=map(int,input().split())
r=min((k*l)//nl,c*d,p//np)
print(r//n)