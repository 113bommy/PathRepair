s = input()

sa = s.count('a')
sb = len(s) - sa
if sa > sb:
    print(len(s))
else:
    h = sb - sa + 1
    # print(h)
    for k in range(h):
        m = 0
        while m != len(s) - 1:
            if s[m] != 'a':
                break
            else:
                m += 1
        s = s[:m] + s[m + 1:]
    print(len(s))

