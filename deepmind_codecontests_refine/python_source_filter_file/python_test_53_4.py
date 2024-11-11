def solve():
    n, c = input().split()
    n = int(n)
    s = input()
    no_work = True
    for i in s:
        if i != c:
            no_work = False
    if no_work:
        print(0)
        return
    for i in range(n - 1, n // 2, -1):
        if s[i] == c:
            print(1)
            print(i + 1)
            return
    print(2)
    print(n - 1, n)


for _ in range(int(input())):
    solve()
