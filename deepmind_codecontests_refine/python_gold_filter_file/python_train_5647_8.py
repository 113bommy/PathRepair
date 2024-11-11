t=int(input())
for i in range(t):
    n,m=tuple(map(int,input().split()))
    l=[[0]*m]*n
    if(m%2==0):
        for j in range(n):
            for k in range(m):
                if((j)%2==0):
                    if(k==1 and j==0):
                        print("B",end="")
                    elif(k%2==0):
                        print("B",end="")
                    else:
                        print("W",end="")
                else:
                    if(k%2!=0):
                        print("B",end="")
                    else:
                        print("W",end="")
            print()
    else:
        if(n%2==0):
         for j in range(n):
            for k in range(m):
                if((j)%2==0):
                    if(k==1 and j==0):
                        print("B",end="")
                    elif(k%2==0):
                        print("B",end="")
                    else:
                        print("W",end="")
                else:
                    if(k%2!=0):
                        print("B",end="")
                    else:
                        print("W",end="")
            print()
        else:
         for j in range(n):
            for k in range(m):
                if((j)%2==0):
                    if(k%2==0 ):
                        print("B",end="")
                    else:
                        print("W",end="")
                else:
                    if(k%2!=0):
                        print("B",end="")
                    else:
                        print("W",end="")
            print()