n,m=map(int,input().split())
x=n//m
y=n-x*m
kmin=y*(((x+1)*x)//2)+(m-y)*((x*(x-1))//2)
z=n-(m-1)
kmax=((z*(z-1))//2)
print(kmin,kmax,sep=" ")
