for _ in range(int(input())):

    n, a, b = map(int, input().split())
    s = input()
    ans = a * n

    c = 0
    for x in range(1, n):
        if s[x] != s[x-1]:
            c += 1

    k = max(b*n, b*((c+1)//2+1))
    print(ans + k)