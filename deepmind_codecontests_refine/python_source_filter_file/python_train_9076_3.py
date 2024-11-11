q = int(input())
for i in range(q):
    s = input()
    ls = len(s)
    s += '0'
    j = 0
    res = ''
    while j < ls:
        if s[j] != s[j+1]:
            res += s[j]
            j += 1
        else:
            j += 2
    print("".join(sorted(list(res))))
