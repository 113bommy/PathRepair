n,k,l,c,d,p,nl,np=map(int,input().split(" "))
x=(k*l)//nl
y=c*d
z=(p//np)
print(min(x,y,z)//n)