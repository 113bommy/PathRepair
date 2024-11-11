for _ in range(int(input())):
    n, a = list(map(int, input().strip().split()))
    mat = []
    m = 10**9
    count = 0
    ans = 0
    for i in range(n):
        mat.append(list(map(int, input().strip().split())))
        for j in range(a):
            ans += abs(mat[i][j])
            if mat[i][j]<0:
                count += 1
            m = min(m, abs(mat[i][j]))
    if count%2 == 0:
        print(ans)
    else:
        print(ans - 2*m)