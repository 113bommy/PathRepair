t= int(input())



for _ in range (0,t):



    n= int(input())
    last=-1
    a= list(map(int,input().split()))
    
    count=0
    temp=1
    minn=a[0]
    now=n-1
    mostl=0



    
    for i in range(n-2,-1,-1):
        
        
        if a[now]>a[i]:
            now=i
        else:
            count +=1
        
       
            

    print(count)
