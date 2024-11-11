def mai(a):
    for i in range(a):
        n,x,a,b=map(int,input().split())
        h=max(a,b)
        l=min(a,b)
        r=0
        if(l-x>=1):
            r=h-(l-x)
            print(r)
        else:
            if(l!=1):
                x=x-l+1
            l=1
            
            if(h+x>=n):
                print(n-l)
            else:
                r=(h+x)-l
                print(r)
            
        

mai(int(input()))