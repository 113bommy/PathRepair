n, k = [int(x) for x in input().split()]
if k <= n:
    if k % 2 == 0:
        flag = 1
    else:
        flag = 0
    print(k // 2 - flag)
else:
    if k // 2 > n:
        flag = 0
    else:
        flag = 1        
    print(n - (k // 2) * flag)