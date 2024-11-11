n = int(input())
o = {
    'M': [0 for i in range(367)],
    'F': [0 for i in range(367)],
}

for i in range(n):
    g, s, e = input().split(' ')
    s, e = int(s), int(e)
    for x in range(s, e):
        o[g][x] += 1

e = [2 * max(o['M'][i], o['F'][i]) for i in range(0, 367)]
print(max(e))
