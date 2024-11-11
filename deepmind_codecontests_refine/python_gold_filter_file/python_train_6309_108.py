n,k=[int(i) for i in input().split()]
if 1<=n<=10**18 and 1<=k<=10**18:
    if (n//k)%2==0:
        print("No")
    else:
        print("Yes")
else:
    print("No")
