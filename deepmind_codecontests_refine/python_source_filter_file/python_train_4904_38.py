n=int(input())
if n<=1:
    print("No")
else:
    
    
    if n%2==0:
        k=n//2
        if k%2==0:
            print("Yes")
            print("2",end=" ")
            print("1 3")
            print("")
            print(n-2,end=" ")
            for i in range(1,n+1):
                if i!=1 and i!=3:
                    print(i,end=" ")
        
        else:
            
            print("Yes")
            print(k,end=" ")
            for i in range(1,k+1):
                print(i,end=" ")
            print("")
            print(k,end=" ")
            for i in range(k+1,n+1):
                print(i,end=" ")        
    else:
        print("Yes")
        print(n-1,end=" ")
        for i in range(1,n):
            print(i,end=" ")
        print("")
        print("1",end=" ")
        print(n)
        
  
    