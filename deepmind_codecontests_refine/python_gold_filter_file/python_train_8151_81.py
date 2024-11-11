from sys import stdin,stdout
n,k,l,c,d,p,nl,np=map(int,stdin.readline().split())
x= k*l//nl
y = c*d
z= p//np
w = min(x,y,z)
print(w//n)


