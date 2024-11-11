n, a, b = map(int, input().split())
s = input()
d, c, ans = '', 0, 0
for i in s:
    if i != '*':
        if c == 0 and min(a, b) > 0:
            c = 1 if a > b else 2
            if c == 1:
                a -= 1
            else:
                b -= 1
        elif c == 1 and b > 0:
            c = 2
            b -= 1
        elif c == 2 and a > 0:
            c = 1
            a -= 1
        else:
            c = 0
    else:
        c = 0
    if c != 0:
        ans += 1
print(ans)
