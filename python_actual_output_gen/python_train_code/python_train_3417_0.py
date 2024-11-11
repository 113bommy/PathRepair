t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    n=n-2
    if(n<3):
        print(1)
    else:   
        if(n%m==0):
            print(n//m+1)
        else:    
            print(n//m+2)
