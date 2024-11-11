for u in range(int(input())):
    n=int(input())
    s=input()
    r=''
    x=s
    c=1
    for i in range(n):
        r=r+s[i:n]
        h=s[0:i]
        if((n-i)%2==1):
            h=h[::-1]
        r=r+h
        if(r<x):
            x=r
            c=c+i
        r=''
    print(x)
    print(c)
