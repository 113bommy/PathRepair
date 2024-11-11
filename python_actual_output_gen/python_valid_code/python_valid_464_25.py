t=int(input())
for i in range(t):
    
    st,n=list(map(int,input().split()))
    c=n%4
    k=(n//4)*4+1
    if(st%2==0):
        for j in range(c):
            if(st%2==0):
                st-=k
                k+=1
            else:
                st+=k
                k+=1
        print(k)
    else:
        for j in range(c):
            if(st%2==0):
                st-=k
                k+=1
            else:
                st+=k
                k+=1
        print(k)
    
    