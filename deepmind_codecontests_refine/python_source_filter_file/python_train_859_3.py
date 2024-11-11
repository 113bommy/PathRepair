n = int(input())
c = [*map(int, input().split())]
# if n % 2: c = [n + 1 - i for i in c]
# print(c)
# print()
q = 0
o = []
for i in range(n):
    j = c.index(i + 1)
    m = [1] * i
    if j - i + 1: m.append(j - i + 1)
    m += [1] * (n - 1 - j)
    if i:
        c = c[:i] + c[j:i - 1:-1] + c[j + 1:]
    else:
        c = c[:i] + c[j::-1] + c[j + 1:]
    if len(m) > 1:
        q += 1
        if i % 2: m = m[::-1]
        m = [len(m)] + m
        o.append(' '.join(map(str, m)))
        # print(c)
        # print(m)

# print()
print(q)
print('\n'.join(o))
