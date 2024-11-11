a,b,c=map(int,input().split())
b=int(((a*b)/c)**0.5)
a/=b
c/=a
print(4*(a+b+c))
