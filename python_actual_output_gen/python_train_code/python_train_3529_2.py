e=10**9+7
a,b,n,x=map(int,input().split())
t=pow(a,n,e*max(1,a-1))
print((t*x+b*(t-1)//(a-1))%e if a-1else a*x+b)