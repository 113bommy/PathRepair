n=int(input())
if n==1 or n==2:
    print(1)
    print(1)
elif n==3:
    print(2)
    print("1 3")
else:
    k=2
    print(n)
    while k<=n:
        print(k,end=" ")
        k+=2
    k=1 
    while k<=n:
        print(k,end=" ")
        k+=2
    print("")