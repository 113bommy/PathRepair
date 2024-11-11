x,k,d=map(int,input().split())
m=min(k,x//d)
x-=d*m
k-=m
k%=2
x-=d*k
print(abs(x))