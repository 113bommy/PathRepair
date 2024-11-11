a,b,n=map(int,input().split())
f=lambda x:(a*x)//b-a*(x//b)
print(max(f(b-1),f(n)))