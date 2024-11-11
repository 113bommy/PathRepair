#rough code
n,m,a,b=map(int,input().split())
p=n*a
q=(n//m)*b+(n%m)*a
print(min(p,q))