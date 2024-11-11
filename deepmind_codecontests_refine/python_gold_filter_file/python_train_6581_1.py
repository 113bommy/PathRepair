for _ in range(int(input())):
    n = int(input())
    s = input()
    balance = 0
    index = {0: 1}
    ans = [10**9]
    i = 1
    for x in s:
        if x == 'U':
            balance += 10 ** 9
        elif x == 'D':
            balance -= 10 ** 9
        elif x == 'L':
            balance += 1
        else:
            balance -= 1
        if balance in index:
            ans = min(ans, [i + 1 - index[balance], index[balance], i])
        index[balance] = i + 1
        i += 1
    if ans[0] == 10 ** 9:
        print(-1)
    else:
        print(ans[1], ans[2])
