for _ in range(int(input())):
    n,x = map(int,input().split())
    arr=list(map(int,input().split()))
    arr.sort()
    left_sum = 0
    for i in arr:
        if i<x:
            left_sum+=abs(x-i )
    right_sum = 0
    for i in arr:
        if i>x:
            right_sum+=abs(i-x)
    only_x = False
    for i in arr:
        if i==x:
            only_x=True
            break
    if left_sum==0 and right_sum==0:
        print(0)
    elif right_sum==left_sum and only_x:
        print(1)
    else:
        print(2)
