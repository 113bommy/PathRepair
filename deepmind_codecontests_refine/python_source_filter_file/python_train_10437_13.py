for _ in range(int(input())):
    n=int(input())
    a=list((map(int,input().split())))
    for i in range(0,n-1):
        if i%2==0:
            if a[i]>0:
                a[i]*=(-1)
        else:
            if a[i]<0:
                a[i]*=(-1)
                
        
    print(*a)
                