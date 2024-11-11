def get_invert(string) -> str:
    ans1 = ''
    for e in string:
        ans1 += '1' if e == '0' else '0'
    return ans1


for _ in range(int(input())):
    n = int(input())
    a = input()
    b = input()
    c = 0
    p = n - 1
    ans = []
    while p > -1:
        if a[p] == b[p]:
            p -= 1
            continue
        if a[0] == b[p]:
            if b[p] == '1':
                a = '0' + a[1:]
            else:
                a = '1' + a[1:]
            c += 2
            a = get_invert(a[:p + 1]) + a[p + 1:]
            ans.append(1)
            ans.append(p + 1)
        else:
            c += 1
            a = get_invert(a[:p + 1]) + a[p + 1:]
            ans.append(p + 1)
        p -= 1
    print(c, *ans)
