def check(d):
    count_un = d['?']
    count_d = 0
    st = []
    for i in d:
        if d[i] != 0 and i != '?':
            count_d += 1
        if d[i] == 0:
            st.append(i)
    return (count_d + count_un == 26, st)

s = input()
d = dict()
for i in range(ord('A'), ord('Z') + 1):
    d[chr(i)] = 0
d['?'] = 0
if len(s) < 26:
    print(-1)
else:
    for i in range(26):
        d[s[i]] += 1
    l = 0
    r = 25
    ans = 0
    while True:
        if r == len(s):
            break
        (x, st) = check(d)
        if x:
            help = ''
            for i in range(l, r + 1):
                if s[i] != '?':
                    help += s[i]
                else:
                    help += st[-1]
                    st.pop()
            ans = s[:l] + help + s[r + 1:]
            break
        d[s[l]] -= 1
        l += 1
        r += 1
        if r == len(s):
            break
        d[s[r]] += 1
    new = ''
    if ans != 0:
        for i in ans:
            if i == '?':
                new += 'A'
            else:
                new += i
        print(new)
    else:
        print(-1)
            