t = int(input())
for i in range(t):
    n = int(input())
    if n == 1:
        print(1)
    elif n == 2:
        print(-1)
    else:
        nmat = [[0]*n for j in range(n)]
        lastd = -1
        val = 1
        j = 0
        while j < n:
            if j % 2 == 0:
                for k in range(0, n, 2):
                    nmat[j][k] = val
                    lastd = val
                    val += 1
            else:
                for k in range(1, n, 2):
                    nmat[j][k] = val
                    lastd = val
                    val += 1
            j += 1
        val = lastd
        for j in range(n):
            if j % 2 == 1:
                last = 1
                for k in range(0, n, 2):
                    nmat[j][k] = val
                    val += 1
            else:
                for k in range(1, n, 2):
                    nmat[j][k] = val
                    val += 1
        for j in range(n):
            print(*nmat[j])