for i in range(int(input())):
        n,a,b=map(int,input().split())
        c=0
        if a<=b:
                c=n*a
        else:
                r=n//2
                c=r*b
                n-=r*2
                c+=a*n
        print(c)