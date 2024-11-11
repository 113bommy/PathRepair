t=int(input())
while t>0:
    n=int(input())
    if(n<=30):
        print("NO")
    else:
        
        if((n-30)==6):
            print("YES")
            print(5,6,10,15)
        elif((n-30)==10):
            print("YES")
            print(10,14,15,1)
        elif((n-30)==14):
            print("YES")
            print(10,14,15,5)
        else:
            print("YES")
            print(6,10,14,n-30)
            
    t-=1
