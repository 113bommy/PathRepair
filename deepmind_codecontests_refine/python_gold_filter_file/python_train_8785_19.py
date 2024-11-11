n=int(input())

for i in range(n-1,-1,-1):
    a=i
    for j in range(1,n+1):
        print((n*j)-a,end=" ")
        if(a==0):
            a=n-1
        else:
            a-=1
    print()
