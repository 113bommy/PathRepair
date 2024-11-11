import sys
input = sys.stdin.readline

def swap(s):
    for i in range(s // 2):
        a[i], a[s - i - 1] = a[s - i - 1], a[i]
    p.append(s)
    return

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    m = 0
    for i in range(n):
        if not (a[i] % 2) ^ i:
            m = -1
            break
    if m == -1:
        print(m)
        continue
    p = []
    for i in range(n // 2):
        x, y = a.index(2 * i + 1), a.index(2 * i + 2)
        if x > y:
            swap(x + 1)
            y = x + 1 - y - 1
            swap(y)
            x = y - 1
            swap(n - 2 * i)
            x, y = n - 2 * i - x - 1, n - 2 * i - y - 1
            swap(x + 1)
            swap(n - 2 * i)
        else:
            swap(x + 1)
            swap(y)
            swap(n - 2 * i)
            swap(n - y + 1 - 2 * i)
            swap(n - 2 * i)
    swap(n)
    m = len(p)
    print(m)
    print(*p)