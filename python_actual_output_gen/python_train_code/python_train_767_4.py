for _ in range(int(input())):
    s = input()
    i = 0
    rms = []
    while i < len(s):
        if 'twone' == s[i:i + 6]:
            rms.append(i + 3)
            i += 5
        elif 'one' == s[i:i + 3] or 'two' == s[i:i + 3]:
            rms.append(i + 2)
            i += 3
        else:
            i += 1
    print(len(rms))
    print(' '.join(map(str, rms)))