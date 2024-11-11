n,a,b=map(int,input().split())
print(n*a//(a+b)+min([n%(a+b),a]))