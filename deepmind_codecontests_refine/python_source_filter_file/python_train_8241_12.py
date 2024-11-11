for _ in range(int(input())):
    s = 0
    y = 0
    n, m = list(map(int, input().split()))
    if m > n:
        print(0)
    else:
        number = str(n//m)
        last = int(number[-1])
        for i in range(1, 11):
            t = str(i*m)
            s += int(t[-1])
            if last == i:
                y = s
        ans = ((int(number)-last)*10 * s)//10 + y
        print(ans)