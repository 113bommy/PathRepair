n,m,a=map(int,input().split())
if n%a==0:
    b=n//a
else:
    b=(n//a)+1
if n%b==0:
    c=m//a
else:
    c=(m//a)+1
print(b*c)