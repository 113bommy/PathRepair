x = int (input ())
for i in range (x):
    a = input ().split (" ")
    n=int(a[0])
    s=int(a[1])
    y=list(map(int,input().split(" ")))
    z=0
    j=0
    m=y[0]
    w=1
    q=0
    while  j<len(y)and z+y[j]<=s:
        z+=y[j]
        if y[j]>m:
            w=j+1
            m=y[j]
        q=j
        j+=1
    if q==len(y)-1:
        print(0)
    elif m<=y[q+1]:
        print(q+2)
    elif m>y[q+1]:
        print(w)