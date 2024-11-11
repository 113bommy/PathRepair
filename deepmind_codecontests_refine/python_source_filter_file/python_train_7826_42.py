for i in range(int(input())):
    arr = list(map(int, input().split()))
    print('YES' if arr[1] - arr[0] != 1 else 'NO')