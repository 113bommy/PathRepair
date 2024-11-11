n,a,b=map(int,input().split())
x=n//(a+b)*1.0
c=n-(a+b)*x
print(int(a*x+min(c,a)))
