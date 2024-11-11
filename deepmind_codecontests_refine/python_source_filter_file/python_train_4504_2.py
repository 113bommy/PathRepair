for _ in range(int(input())):
    n, m = map(int, input().split())
    mat = [list(map(int, input().split())) for _ in range(n)]
    bad = False
    for i in range(n):
        for j in range(m):
            c = 4
            if i == 0 or i == n-1:
                c -= 1
            if j == 0 or j == m-1:
                c -= 1
            if mat[i][j] > c:
                bad = True
                break
        if bad:
            break
    if bad:
        print("NO")
        continue
    print("YES")
    print(2, *([3]*(m-1)), 2)
    for _ in range(n-2):
        print(3, *([4]*(m-1)), 3)
    print(2, *([3]*(m-1)), 2)
