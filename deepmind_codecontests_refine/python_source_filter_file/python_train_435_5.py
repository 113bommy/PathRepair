from sys import stdin
from string import ascii_uppercase as y
for _ in range(int(stdin.readline())):
    s,c = stdin.readline().split()
    dct = {q:set() for q in y}
    fl = 0
    for i in range(len(s)):
        dct[s[i]].add(i)
    dct1 = {'A':set()}
    for r in range(1,26):
        dct1[y[r]] = dct1[y[r-1]].union(dct[y[r]])
    for i in range(min(len(s),len(c))):
        if fl:break
        if s[i]<c[i]:
            print(s)
            fl = 1
            break
        elif s[i] == c[i]:
            for x in dct1[s[i]]:
                if x > i:
                    print(s[:i]+s[x]+s[i+1:x]+s[i]+s[x+1:])
                    fl = 1
                    break
        else:
            for x in dct1[c[i]]:
                if x > i:
                    print(s[:i]+s[x]+s[i+1:x]+s[i]+s[x+1:])
                    fl = 1
                    break
            if not fl:
                for x in dct[c[i]]:
                    if x > i:
                        u = s[:i] + s[x]+ s[i + 1:x] + s[i]+s[x + 1:]
                        if u < c:
                            print(u)
                            fl = 1
                            break
                if not fl:
                    print('---')
                    fl = 1
                    break
    if not fl:
        if len(s)<len(c):
            print(s)
        else:
            print('---')

