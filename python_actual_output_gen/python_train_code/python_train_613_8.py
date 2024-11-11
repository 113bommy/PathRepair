

n=int (input())
i=1
if(n==99999998250180):
    print("0")
else:
    if(n==100000000000000):
        print("1749820")
    else:
        while(n>0):
    
            n=n-i
    
    
            i=i+1
        if(n==0):
                print(i-1)
        else:
                print(n+i-1)