for i in range(int(input())):
    n=int(input())
    q=n//3
    r=n%3
    if(r==0):
        print(q,q)
    elif(r==1):
        print(q+1,q)
    else:
        print(q,q+1)
    
