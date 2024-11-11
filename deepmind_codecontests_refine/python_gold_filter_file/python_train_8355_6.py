for t in range(int(input())):
    n,x,y=map(int,input().split())
    a=[]
    for j in range (1,n):
        
        #print(y-x,n-j)
        
        if (y-x)%(n-j)==0:
            e=(y-x)//(n-j)
            #print(e)
            for i in range(x,y+1,e):
                a.append(i)
            break      
    l=len(a)
    if l<n:
        d=n-l
        while(x-e>0 and d>0):
            a.append(x-e)
            x=x-e
            d-=1
    l=len(a) 
    if l<n:
        d=n-l
        while(d>0):
            a.append(y+e)
            y=y+e
            d-=1
    print(*a)                        



       




