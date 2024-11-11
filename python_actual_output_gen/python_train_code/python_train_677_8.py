try:
    n=int(input())
    if(n%2==0):
        print(int(n/2))
        for i in range(int(n/2)):
            print(2,end=" ")
    else:
        print(int(n/2)+1)
        for i in range(1,int(n/2)):
            print(2,end=" ")
        print(3,end=" ")
        
except Exception:
    pass