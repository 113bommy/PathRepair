d = {'a', 'b', 'c'}
for _ in range(int(input())):
    s = input()
    if s.find('aa') != -1 or s.find('bb') != -1 or s.find('cc') != -1:
        print(-1)
    elif s == '?':
        print('a')
    else:
        s = list(s)
        if s[0] == '?':
            if s[1] in d:
                for c in d:
                    if c != s[1]:
                        s[0] = c
                        break
            else:
                s[0] = 'a'
        if s[-1] == '?':
            if s[-2] in d:
                for c in d:
                    if c != s[-1]:
                        s[-1] = c
                        break
            else:
                s[-1] = 'a'
        for i in range(1, len(s) - 1):
            if s[i] == '?':
                if s[i + 1] == '?':
                    for c in d:
                        if c != s[i - 1]:
                            s[i] = c
                else:
                    s[i] = (d ^ set([s[i - 1], s[i + 1]])).pop()
        print(''.join(s))
