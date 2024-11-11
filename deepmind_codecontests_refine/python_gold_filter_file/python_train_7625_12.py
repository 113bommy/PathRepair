def multiple_input(): return map(int, input().split())


def list_input(): return list(map(int, input().split()))


for _ in range(int(input())):
    x = input()
    r, s, p = 0, 0, 0
    for i in x:
        if i == 'R':
            r += 1
        elif i == 'S':
            s += 1
        else:
            p += 1
    if r == s == p:
        ans = x
    elif r == s and r > p:
        c = len(x) // 2
        ans = c * 'P' + c * 'R'
        if len(x) % 2 != 0:
            ans += 'R'
    elif s == p and s > r:
        c = len(x) // 2
        ans = c * 'R' + c * 'S'
        if len(x) % 2 != 0:
            ans += 'S'
    elif r == p and r > s:
        c = len(x) // 2
        ans = c * 'P' + c * 'S'
        if len(x) % 2 != 0:
            ans += 'S'
    elif r > s and r > p:
        ans = len(x) * 'P'
    elif s > r and s > p:
        ans = len(x) * 'R'
    elif p > s and p > r:
        ans = len(x) * 'S'
    print(ans)