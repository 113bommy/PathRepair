for _ in range(int(input())):
    n = int(input())
    cnt = 0
    for i in range(30000,0,-1):
        s = 1.5*(i * (i + 1)) - i
        if s <= n:
            n -= s
            cnt += 1
    print(cnt)