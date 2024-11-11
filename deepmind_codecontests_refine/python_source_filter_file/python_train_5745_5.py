t = int(input())
while t > 0:
    t = t-1
    res = True
    n, m, k = [int(x) for x in input().split(' ')]
    arr = [int(x) for x in input().split(' ')]
    for i in range(0, n-1):
        m += arr[i] - (arr[i+1] - k)
        if m < 0:
            res = False
            break
    if res:
        print("YES")
    else:
        print("NO")