t = int(input())

class Query():
    def __init__(self, a = 0, b = 0, c = 0):
        self.a = a
        self.b = b
        self.c = c


for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = []
    for i in range(2, n + 1):
        if (a[i - 1] % i) != 0:
            b.append(Query(1, i, i - (a[i - 1] % i)))
            a[0] -= a[i - 1] % i
            a[i - 1] += i -  (a[i - 1] % i)
        b.append(Query(i, 1, a[i - 1] // i))
        a[0] += a[i - 1]
        a[i - 1] = 0
    if (a[0] % n) != 0:
        print(-1)
        continue
    v = a[0] // n
    for i in range(2, n + 1):
        b.append(Query(1, i, v))
    print(len(b))
    for i in b:
        print(i.a, i.b, i.c)