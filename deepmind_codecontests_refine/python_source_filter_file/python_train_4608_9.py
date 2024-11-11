try:
    t=int(input())
    while(t):
        a,b,n,m=[int(x) for x in input().split()]
        cook=a+b
        if(a>b):
            min=b
        else:
            min=a
        mem=n+m
        if(cook>=mem and min>=n):
            print("Yes")
        else:
            print("No")
        
        
        t-=1
        
except:
    pass