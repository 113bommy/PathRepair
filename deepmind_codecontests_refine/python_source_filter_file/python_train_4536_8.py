N = int(input())
arr = list(map(int, input().split()))

if N == 1:
    if arr[0] % 2 == 0:
        print("YES")
    else:
        print("NO")
else:
    flag = True
    for i in range(N - 1):
        if arr[i] < 0:
            flag = False
            break
        if arr[i] == 0:
            continue
        if arr[i] % 2 == 1:
            arr[i + 1] -= arr[i]
            arr[i] = 0
        elif arr[i] % 2 == 0:
            arr[i] = 0

    if not flag:
        print("NO")
    else:
        if arr[-2] == 0 and arr[-1] % 2 == 0:
            print("YES")
        else:
            print("NO")
