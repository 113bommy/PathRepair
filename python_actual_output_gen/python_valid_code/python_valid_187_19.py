n,a,b=map(int,input().split())
x=n/(a+b)-n%(a+b)
c=n-(a+b)*x
print(int(a*x+min(c,a)))