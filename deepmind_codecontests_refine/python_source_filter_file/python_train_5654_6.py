n,ohh,wow= list(map(int , input().split()))
if(wow==0):
    if(n>=ohh+2):
        print(1,end=" ")
        print(1,end=" ")
        for i in range(1,ohh+1):
            print(i+1,end=" ")
        for i in range(n-ohh-2):
            print(ohh+1,end=" ")
    elif(ohh==0):
        for i in range(n):
            print(1,end=" ")
    else:
        print(-1) 
else:
    ans=1
    print(ans,end=" ")
    for i in range(wow):
        ans*= 4
        print(ans,end=" ")
    for i in range(1,ohh+1):
        print(ans+i,end=" ")
    for i in range(n-ohh-wow-1):
        print(1,end=" ")