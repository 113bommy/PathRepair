for _ in range(int(input())):
    n = int(input())
    arr = [int(x) for x in input().split()]
    maxi = max(arr)
    max_ind = [i for i, val in enumerate(arr) if val == maxi]
    if len(max_ind) == n:
        print(-1)
        continue
    for i in max_ind:
        if i != n-1:
            if arr[i+1] < arr[i]:
                print(i)
                break
        if i != 0:
            if arr[i-1] < arr[i]:
                print(i)
                break
    else:
        print(-1)
                