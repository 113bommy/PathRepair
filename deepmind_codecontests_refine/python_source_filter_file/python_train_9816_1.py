n, Q = map(int, input().split())
cnt = 1
F = [1]
for i in range(1, 17):
    F.append(F[-1] * i)
st = max(0, n - 15)
a = [0] * (n + 1)
vs = [0] * (n + 1)
for i in range(n):
    a[i] = a[i - 1] + i
for _ in range(Q):
    q = list(map(int, input().split()))
    if q[0] == 1:
        l, r = q[0], q[1]
        print(a[r] - a[l - 1])
        continue
    x = q[1]
    cnt += x
    hav = cnt
    for i in range(st, n + 1):
        vs[i] = 0
    for i in range(st, n):
        tmp = 0
        for j in range(st, n + 1):
            if not vs[j]:
                tmp += F[n - i]
                if tmp >= hav:
                    hav -= tmp - F[n - i]
                    a[i] = a[i - 1] + j
                    vs[j] = 1
                    break
    for i in range(st, n + 1):
        if not vs[i]:
            a[n] = a[n - 1] + i
    

        