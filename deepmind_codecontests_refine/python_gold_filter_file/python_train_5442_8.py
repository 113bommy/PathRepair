for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,list(input())))
    if n%2:
        odd=False
        for i in range(0,n,2):
            if arr[i]%2:
                odd=True
                break
        if odd:
            print(1)
        else:
            print(2)
    else:
        even=False
        for i in range(1,n,2):
            if arr[i]%2==0:
                even=True
                break
        if even:
            print(2)
        else:
            print(1)
        