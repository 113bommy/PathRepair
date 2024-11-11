for _ in range(int(input())):
    arr = list(map(int, input().split()))
    arr = sorted(arr)
    if arr[1] == arr[2]:
        print("YES")
        print(arr[1], arr[0], 0)
    else:
        print("NO")