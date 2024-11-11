length = int(input())
arr = sorted(list(map(int, input().split())))
if arr[0] > 1:
    print(1)
else:
    for x in range(length - 1):
        if abs(arr[x] - arr[x + 1]) > 1:
            print(arr[x] + 1)
            break
    else:
        print(arr[-1] + 1)