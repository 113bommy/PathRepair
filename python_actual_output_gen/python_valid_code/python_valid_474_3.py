def solve():
    n, h = map(int, input().split())
    a = list(map(int, input().split()))

    if n == 1:
        print(h)
        return

    b = list()
    for i in range(n):
        b.append(a[i] - a[i - 1])

    b.sort()

    cnt = n
    for i in range(len(b)):
        check = h // cnt

        if(h % cnt != 0):
            check += 1

        if b[i] >= check:
            print(check)
            return
        else:
            h -= b[i]
            cnt -= 1
    print(h)

for _ in range(int(input())):
    solve()