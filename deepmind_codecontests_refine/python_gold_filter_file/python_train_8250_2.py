for _ in range(int(input())):
    n = int(input())
    a = input()
    b = input()
    ans = []
    inv, rev = 0, 0
    cnt = 0
    for i in range(n - 1, -1, -1):
        c = cnt // 2
        if cnt % 2 == 1:
            rev = n - c - 1
        else:
            rev = c

        f = a[rev]
        if inv % 2 == 1:
            if f == '0':
                f = '1'
            else:
                f = '0'
        if f == b[i]:
            ans.append(1)
        inv += 1
        ans.append(i + 1)
        cnt += 1
    print(len(ans), *ans)
