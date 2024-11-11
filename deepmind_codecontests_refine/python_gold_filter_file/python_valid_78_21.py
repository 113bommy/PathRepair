for i in range(int(input())):
    l,r = tuple(map(int,input().split()))
    if r%2==0:
        if r//2 <l:
            print(r%l)
        else:
            print(r//2 -1)
    else:
        if r//2 <l:
            print(r%l)
        else:
            print(r//2)