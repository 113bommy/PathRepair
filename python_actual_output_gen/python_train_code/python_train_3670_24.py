def answer():
    a=input().split()
    s,n=a[0],int(a[1])
    k=0
    while n:
        if s[-1]=="0":
            s=s[:-1]
        else:
            s=s[:-1]+str(int(s[-1])-1)
        n-=1
    return int(s) 
answer()