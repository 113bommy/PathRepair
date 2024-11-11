s = input()
s = s[5:]

if len(s) < 2:
    print(0)
elif len(s) == 2:
    print(1)
    print(s)
elif len(s) == 3:
    print(2)
    for suff in sorted([s, s[-2:]]):
        print(suff)
else:
    D = [[False for _ in range(2)] for _ in range(len(s))]

    suffixes = { s[-2:], s[-3:] }

    D[-2][0] = True
    D[-3][1] = True

    for i in range(len(s) - 4, -1, -1):
        if (s[i:i+2] != s[i+2:i+4] and D[i+2][0]) or D[i+2][1]:
            D[i][0] = True
            suffixes |= { s[i:i+2] }
        if (i <= len(s) - 6 and s[i:i+3] != s[i+3:i+6] and D[i+3]) or D[i+3][0]:
            D[i][1] = True
            suffixes |= { s[i:i+3] }

    print(len(suffixes))
    for suffix in sorted(suffixes):
        print(suffix)
