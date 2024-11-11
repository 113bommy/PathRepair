n,k=map(int,input().split())
if k%2==1:
    print(1)
else:
    mid=2**(n-1)
    if k==mid:
        print(n)
    else:
        if k<mid:
            t=k
        else:
            t=2**(n-1)-k
        p=0
        while t%2==0:
            p+=1 
            t=t//2
        print(p+1)
    