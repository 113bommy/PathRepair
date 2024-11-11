for i in range(int(input())):
    x,n=map(int,input().split())
    if x%2==0:
        if n%4==1 or n%4==-1:
            print(x-n)
        elif n%4==2 or  n%4==-2:
            print(1+x)
        elif n%4==3 or  n%4==-3:
            print(n+1+x)
        else:
            print(x)
    else:
        if n%4==1 or n%4==-1:
            print(x+n)
        elif n%4==2 or  n%4==-2:
                print(n+x)
        elif n%4==3 or  n%4==-3:
            print(x-1-n)
        else:
            print(x)    


    


                
    



    

    
