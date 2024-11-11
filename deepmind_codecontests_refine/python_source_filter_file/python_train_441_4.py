t=int(input())
while t>0:
    n=int(input())
    a1=list(map(int,input().split()))
    a2=list(map(int,input().split()))
    a3=list(map(int,input().split()))
    print(a1[0],end=" ")
    curr=a1[0]
    for i in range(1,n-1):
        if a1[i]!=curr:
            curr=a1[i]
        elif a2[i]!=curr:
            curr=a2[i]
        elif a3[i]!=curr:
            curr=a3[i]
        print(curr,end=" ")
    if a1[n-1]!=a1[0] and a1[n-1]!=curr:
        print(a1[n-1],end=" ")
    if a2[n-1]!=a1[0] and a2[n-1]!=curr:
        print(a2[n-1],end=" ")
    else:
        print(a3[n-1],end=" ")
    print("")
    t-=1
        
