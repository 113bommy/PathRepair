n,m= map(int,input().split())
d=1
for i in range(1,n):
    l=''

    if i%2!=0:
        for k in range(m):
            l=l+"#"
           
    else:
        if d==1:
            for k in range(m-1):
                l=l+'.'
            l=l+"#"
            d=2
        else:
            for k in range(m-1):
                l=l+"."
            l="#"+l
            d=1
    print(l)