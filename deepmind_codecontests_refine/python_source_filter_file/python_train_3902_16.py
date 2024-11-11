n,m=list(map(int,input().strip().split()))
for i in range(1,n+1):
    if i%2 !=0:
        for j in range(m):
            print("#",end="")
        print("",end="\n")
    else:
        if i%4==0:
            print("#",end="")
            for j in range(m-1):
                print("-",end="")
            print("",end="\n")
        elif i%2==0:
            for j in range(m-1):
                print("-",end="")
            print("#")
            
    
