a,b,c=map(int,input().split())
f=min(c,b+1)
q=f-1
d=q-1
if a<d:
    if b>a and c>b:
        print(a+a+1+a+2)
    else:
        print(0)
else:
    print(max(0,q+f+d))