q = int(input())


def get_k(arr):
    p = [0]
    for i in arr:
        p.append(p[-1] + i)
    j = 0
    for i in range(len(arr)):
        if a[i] < 0:
            j = i
    return j

while q:
    q -= 1
    n = int(input())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    cs = []
    for i in range(len(a)):
        if not b[i]:
            cs.append(a[i])
    cs.sort()
    ncs = cs[:]
    cs.reverse()
    _a = a[:]
    j = 0
    for i in range(len(a)):
        if not b[i]:
            a[i] = cs[j]
            j += 1
    j = 0
    for i in range(len(_a)):
        if not b[i]:
            _a[i] = ncs[j]
            j += 1
    print(*(a if get_k(a) < get_k(_a) else _a))
