a,b,c=list(map(int,input().split()))
s=max(a,b,c)
if s==a:
    if b+c>=a:
        print(0)
    else:
        print(a+1-b-c)
elif s==b:
    if a+c>=b:
        print(0)
    else:
        print(b+1-a-c)
else:
    if a+b>=c:
        print(0)
    else:
        print(c+1-a-b)