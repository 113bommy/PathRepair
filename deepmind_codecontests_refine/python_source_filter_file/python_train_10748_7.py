for _ in range(int(input())):
    n,x=map(int,input().split())
    a=list(map(int,input().split()))

    b=0
    #even
    for xx in a:
        if(xx%2==0):
            b+=1
    c=len(a)-b
        
    
    if(len(a)==x):
        if(sum(a)%2==0):
            print("No")
        else:
            print("Yes")
    elif(c==0):
        print("No")
    elif(b==0)and(c%2==0):
        print("No")
    else:
        print("Yes")
        
        

                       
