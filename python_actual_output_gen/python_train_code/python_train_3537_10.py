s = input()
a = list("abcdefghijklmnopqrstuvwxyz")
if s == "zyxwvutsrqponmlkjihgfedcba":
    print(-1)
elif len(s) != 26:
    nokori = set(a) - set(s)
    nokori = sorted(nokori, key=a.index)
    print(s + nokori[0])
else:
    for i in range(1, 27):
        if s[-i] <= s[-i + 1]:
            break
    s_ = sorted(s[-i:])
    for j in s_:
        if j > s[-i]:
            break
    print(s[:-i] + j)