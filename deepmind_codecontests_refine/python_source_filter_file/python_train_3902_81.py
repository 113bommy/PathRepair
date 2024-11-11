m,n=map(int,input().split())
c=0
for i in range(1,m+1) :
    if i%2!=0 :
        for i in range(n) :
            print("#",end="")
        print()
    else :
        c=c+1
        if c%2!=0 :
            for i in range(n-1) :
                print(".",end="")
            for i in range(m-1,m) :
                print("#",end="")
            print()
        else :
            for i in range(0,1) :
                print("#",end="")
            for i in range(1,m) :
                print(".",end="")
            print()

