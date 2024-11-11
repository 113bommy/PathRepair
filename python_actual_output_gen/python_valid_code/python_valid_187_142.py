n,a,b=map(int,input().split())
p,q=divmod(n,(a+b))
print(p*b + [b,q][q<b]) 