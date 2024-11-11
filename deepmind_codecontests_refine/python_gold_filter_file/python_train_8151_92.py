n,k,l,c,d,p,nl,np=map(int,input().split())
a=int((k*l)//nl)
b=c*d
e=int(p//np)
print(int(min(a,b,e)//n))