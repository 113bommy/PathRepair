for i in range(int(input())):
    arr = list(map(int, input().split()))
    print('YES' if arr[0] - arr[1] != 1 else 'NO')