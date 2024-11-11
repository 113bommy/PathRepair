a,b,n=map(int,input().split())
m=min(n,b)
tmp=(a*m//b)-(((m-1)//b)*a)    
print(tmp)