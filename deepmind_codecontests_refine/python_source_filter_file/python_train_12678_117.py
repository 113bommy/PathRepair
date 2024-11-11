n,a,b=map(int,input().split())
print(a*n//(a+b)+min(n%(a+b),a))