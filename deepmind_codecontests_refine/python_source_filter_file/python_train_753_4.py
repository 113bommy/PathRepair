t=int(input())
for i in range(0,t):
    n,k=map(int,input().split())
    
    ls=list(map(int,input().rstrip().split()))
    
    if(k%2==1):
        maxx=ls[0]
        for l in range(0,n):
            if ls[l]>maxx:
                maxx=ls[l]
        for l in range(0,l):
            ls[l]=maxx-ls[l]
        
    else:
        j=0
        while(j<=1):
            maxx=ls[0]
            for l in range(0,n):
                if ls[l]>maxx:
                    maxx=ls[l]
            for l in range(0,n):
                ls[l]=maxx-ls[l]
            j=j+1
    for j in ls:
        print(j,end=" ")
    print(" ")