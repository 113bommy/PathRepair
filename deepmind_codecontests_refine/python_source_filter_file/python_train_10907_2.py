x,k,d=map(int,input().split())
x=abs(x)
m=min(k,x//d)
x-=d*m
k-=m
k%=2
print(abs(x))