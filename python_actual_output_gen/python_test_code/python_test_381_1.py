t = input()
k = t.find('=')
n = 2 * k - len(t) - 3
if n == 2:
    if t[1] != '+': t = t[1: ] + '|'
    else: t = t[: k - 1] + t[k: ] + '|'
elif n == -2: t = '|' + t[: -1]
elif n != 0: t = 'Impossible'
print(t)