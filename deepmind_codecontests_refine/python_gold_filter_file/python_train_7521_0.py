for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    s = []
    for i in range(n + 1):
        s.append('')
    j = 0
    k = 0
    for i in a:
        if i > len(s[j]):
            if k < 26:
                s[j] += chr(97 + k) * (i - len(s[j]))
                k += 1
            else:
                s[j] += chr(130 - k) * (i - len(s[j]))
                k = 13
        s[j + 1] = s[j][:i]
        if i == 0 and j == 0:
            s[j] = 'kite'
            s[j + 1] = 'tight'
        if i == 0 and j != 0:
            if s[j][0] == 'z':
                s[j + 1] = 'a'
            else:
                s[j + 1] = chr(ord(s[j][0]) + 1)
        j += 1
    for i in s:
        print(i)
