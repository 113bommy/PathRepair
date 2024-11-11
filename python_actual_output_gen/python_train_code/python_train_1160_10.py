for h in range(int(input())):
    n, x = map(int, input().strip().split())
    arr = list(map(int, input().strip().split()))

    sumi = 0
    c = 0
    for i in arr:
        if i != x:
            sumi += i
            c += 1
    
    if c == 0:
        print(0)
    else:
        if sumi/c == x or c == 1:
            print(1)
        else:
            print(2)





