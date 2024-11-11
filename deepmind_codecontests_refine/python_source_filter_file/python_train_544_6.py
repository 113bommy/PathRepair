def test(s, win=False):
    if len(s) < 2:
        return win
    j = 1
    while j < len(s):
        if s[0] != s[j]:
            if j == 1:
                return test(s[2:0], not win)
            else:
                return test(s[:j - 1] + s[j + 1:], not win)
        else:
            j += 1
    return win


d = {True: 'DA', False: 'NET'}
n = int(input())
for i in range(n):
    print(d[test(input())])