t = int(input())
for q in range(t):
    n, k = [int(i) for i in input().split(' ')]
    a = [[0 for i in range(n)] for j in range(n)]
    j_sm = 0
    m = 0
    while k > 0:
        for i in range(n):
            if k > 0:
                k -= 1
                a[i][(i + j_sm) % n] = 1
            else:
                m = 2
                break
        j_sm += 1
    print(m)
    for i in range(n):
        for j in range(n):
            print(a[i][j], end=' ')
        print()