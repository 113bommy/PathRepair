n=int(input())
if n==1 or n==2:
    print(1)
    print(1)
elif n==3:
    print(2)
    print(1,3)
elif n==4:
    print(3)
    print(1,4,2)
else:
    if n%2==0:
        print(n)
        first=list(range(1,n//2+1))
        second=list(range(n//2+1,n+1))
        for i in range(len(first)):
            print("%d %d"%(first[i],second[i]),end=" ")
        print()
    elif n%2==1:
        print(n)
        first=list(range(1,n//2+2))
        second=list(range(n//2+2,n+1))
        for i in range(len(second)):
            print("%d %d"%(first[i],second[i]),end=" ")
        print(first[-1])
