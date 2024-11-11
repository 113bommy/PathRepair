from sys import stdin


for _ in range(int(stdin.readline())):
    s = stdin.readline()
    d = {}
    prev = 1
    for idx, val in enumerate(s[1:], start=1):
        if val != s[idx-1]:
            if prev % 2 == 1:
                d[s[idx-1]] = True
            prev = 1
        else:
            prev += 1
    print(''.join(sorted(d.keys())))

