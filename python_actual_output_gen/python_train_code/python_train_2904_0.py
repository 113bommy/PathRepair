for i in range(int(input())):
    n=int(input())
    k=2
    while((2**k)-1<=n):
        f=n//((2**k)-1)
        if str(f)[-2:]=='.0':
            print(int(f))
            break
        k=k+1