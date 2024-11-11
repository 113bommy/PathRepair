def decSum(n, sm, mn):
    print(n,sm,mn)
    if mn + n > 10 :
        return 0
    elif sum(range(mn, mn + n)) > sm or sum(range(10 - n, 10)) < sm:
        return 0
    elif n == 1:
        return 1
    else:
        a = 0
        for i in range(mn, 10 if sm >= 10 else sm):
            a += decSum(n - 1, sm - i, i + 1)
        return a
while True:
    n, sm = map(int, input().split())
    if n == 0:
        break
    print(decSum(n, sm, 0))