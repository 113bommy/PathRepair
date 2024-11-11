for _ in range(int(input())):
    n=int(input())
    if(n<31):
        print("NO")
    else:
        print("YES")
        if ((n-30) in [6,10,14]):
            print(15,10,6,n-31)
        else:
            print(6,10,14,n-30)
