for t in range(int(input())) :
    n, arr = input(), list(map(int,input().split()))[::-1]
    m, res = arr[0], -1
    for i in arr :
        if(m > i) :
            m = i
        else :
            res += 1
    print(res)