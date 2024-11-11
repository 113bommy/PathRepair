from sys import stdin, stdout


def cheap_dinner(n1, n2, n3, n4, a_a, b_a, c_a, d_a, dic_a, dic_b, dic_c):

    INF = 10**10

    d_a.sort(key=lambda x: x[1])
    for ci in range(1, n3+1):
        found = False
        for d in d_a:
            if ci not in dic_c or (d[0] + 1) not in dic_c[ci]:
                c_a[ci-1][1] += d[1]
                found = True
                break
        if not found:
            c_a[ci - 1][1] = INF

    c_a.sort(key=lambda x: x[1])
    for bi in range(1, n2+1):
        found = False
        for c in c_a:
            if c[1] == INF:
                break

            if bi not in dic_b or (c[0] + 1) not in dic_b[bi]:
                b_a[bi-1][1] += c[1]
                found = True
                break
        if not found:
            b_a[bi - 1][1] = INF

    b_a.sort(key=lambda x: x[1])
    r = INF
    for ai in range(1, n1 + 1):
        for b in b_a:
            if b[1] == INF:
                break

            if ai not in dic_a or (b[0] + 1) not in dic_a[ai]:
                r = min(r, a_a[ai-1][1] + b[1])
                break

    if r == INF:
        return -1
    else:
        return r


n1, n2, n3, n4 = map(int, stdin.readline().split())

# a_a = list(map(mapFunc, enumerate(stdin.readline().split())))
# b_a = list(map(mapFunc, enumerate(stdin.readline().split())))
# c_a = list(map(mapFunc, enumerate(stdin.readline().split())))
# d_a = list(map(mapFunc, enumerate(stdin.readline().split())))
a_a = list(map(int, stdin.readline().split()))
b_a = list(map(int, stdin.readline().split()))
c_a = list(map(int, stdin.readline().split()))
d_a = list(map(int, stdin.readline().split()))

for i in range(n1):
    a_a[i] = [i, a_a[i]]
for i in range(n2):
    b_a[i] = [i, b_a[i]]
for i in range(n3):
    c_a[i] = [i, c_a[i]]
for i in range(n4):
    d_a[i] = [i, d_a[i]]

m1 = int(stdin.readline())
dic_a = {}
for _ in range(m1):
    a, b = map(int, stdin.readline().split())
    if a not in dic_a:
        dic_a[a] = set()
    dic_a[a].add(b)

m2 = int(stdin.readline())
dic_b = {}
for _ in range(m2):
    b, c = map(int, stdin.readline().split())
    if b not in dic_b:
        dic_b[b] = set()
    dic_b[b].add(c)

m3 = int(stdin.readline())
dic_c = {}
for _ in range(m3):
    c, d = map(int, stdin.readline().split())
    if c not in dic_c:
        dic_c[c] = set()
    dic_c[c].add(d)

r = cheap_dinner(n1, n2, n3, n4, a_a, b_a, c_a, d_a, dic_a, dic_b, dic_c)
stdout.write(str(r))
