s = input()
n = i = e = t = 0
for k in range(len(s)):
    if s[k] == 'n':
        n += 1
    elif s[k] == 'i':
        i += 1
    elif s[k] == 'e':
        e += 1
    elif s[k] == 't':
        t += 1
#n += (n % 3) * (n // 3)
if n == 5:
    print(min(2, i, e // 3, t))
else:
    print(max(0, min(n // 2, i, e // 3, t)))
