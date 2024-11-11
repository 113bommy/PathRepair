t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    am = min(a)
    bm = min(b)
    c = 0
    for i in range(n):
        if a[i] == am and b[i] == bm:
                continue
        elif a[i] == am:
            c += b[i] - am
        elif b[i] == bm:
            c+= a[i] - am
        else:
            c += max(a[i]-am, b[i]-bm)
    print(c)