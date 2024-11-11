s = input()
a = input()
b = input()

ans = 0
for x in range(2):
    i = s.find(a)
    j = s.rfind(b)
    if i != -1 and j != -1 and i + len(a) <= j:
        ans ^= (1 << x)

    s = ''.join(reversed(s))

print(['fantasy', 'forward', 'backward', 'both'][ans])
