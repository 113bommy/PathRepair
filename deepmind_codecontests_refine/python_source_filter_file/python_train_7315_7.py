test = int(input())
for _ in range(test):
    n = int(input())
    arr = list(map(int, input().split()))
    flag = False
    for i in range(1,n):
        if arr[i]>arr[i-1]:
            flag = True
            break
    
    if flag:
        print('YES')
    else:
        print('NO')