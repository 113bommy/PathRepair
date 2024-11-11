for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    if n % 2 == 0:
        print('YES')
        continue
    ok = False
    for i in range(1, n):
        if arr[i] < arr[i - 1]:
            ok = True
    if ok:
        print('YES')
    else:
        print('NO')
