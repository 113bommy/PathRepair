def main(s):
    if len(s) == 0:
        return []
    if len(s) == 1:
        return [[s], [1]]
    s = s[::-1]
    sres = [s[0]]
    nres = [1]
    if s[0] == s[1]:
        sres.append('')
        nres.append(0)
    else:
        sres.append(s[:2])
        nres.append(2)
    for i in range(2, len(s)):
        st = s[i] + sres[-1]
        nt = nres[-1] + 1
        if nt > 10:
            st = st[:5] + '...' + st[-2:]
        if s[i] == s[i-1] and st > sres[-1]:
            st = sres[-2]
            nt = nres[-2]
        sres.append(st)
        nres.append(nt)
    return [sres, nres]


s = input()
sres, nres = main(s)

for i in range(len(s)-1, -1, -1):
    print(nres[i], sres[i])

