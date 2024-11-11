a, b = [int(j) for j in input().split(" ")]
c1=0
c2=0
if a==b:
    print(a)
else:
    c1=min(a,b)
    if a>b:
        a=a-c1
        c2=a/2
    else:
        b=b-c1
        c2=b/2
    print(c1,int(c2))
