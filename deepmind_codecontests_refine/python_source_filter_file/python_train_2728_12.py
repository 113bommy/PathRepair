T = int(input())
for case in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    ok = False
    for i in range(1, n):
        if abs(a[i] - a[i - 1] > 2):
            ok = True
            ans = (i, i + 1)
            break
    if ok:
        print('YES')
        print(ans[0], ans[1])
    else:
        print('NO')
