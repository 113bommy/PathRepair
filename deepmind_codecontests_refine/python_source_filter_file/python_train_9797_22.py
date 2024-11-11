n, k = map(int, input().split())

if n == 1:
    print(1)
    print(1)
    exit()

if k >= n//2:
    print(1)
    print(n//2)
else:
    m = 1001
    temp = -1
    for r1 in range(0, k+1):
        for r2 in range(0, k+1):
            t = n-(r1+1+k)-(r2+1+k)
            if t < 0:
                continue
            if t%(2*k+1) == 0:
                x = t//(2*k+1)
                if x+2 <= m:
                    m = x+2
                    temp = [r1, r2, x]
    print(m)
    r1, r2, x = temp
    ans = [r1+1]
    for i in range(x):
        cur = ans[-1]
        ans.append(cur+2*k+1)
    ans.append(n-r2)
    print(*ans)
