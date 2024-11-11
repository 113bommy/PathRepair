def long_numbers(s, t):
    m = max(len(s), len(t))
    for i in range(m):
        sn = '0'
        if len(s) - 1 + i >= 0:
            sn = s[len(s) - 1 + i]
        tn = '0'
        if len(t) - 1 + i >= 0:
            tn = t[len(t) - 1 + i]
        if sn < tn:
            return '<'
        if sn > tn:
            return ">"
    return "="


s1 = input()
s2 = input()
print(long_numbers(s1, s2))
