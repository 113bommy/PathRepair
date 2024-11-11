def go(x, y):
    if x + 1 < n:
        if a[x+1][y] == "1":
            a[x+1][y] = "0"
            go(x+1, y)
    if x-1 >= 0:
        if a[x-1][y] == "1":
            a[x-1][y] = "0"
            go(x-1, y)

    # if y + 1 < n:
    #     if a[x][y+1] == "1":
    #         a[x][y+1] = "0"
    #         go(x, y+1)
    if y-1 >= 0:
        if a[x][y - 1] == "1":
            a[x][y - 1] = "0"
            go(x, y - 1)


t = int(input())
for u in range(t):
    n = int(input())
    a = []
    for _ in range(n):
        a.append(list(input()))
    # print(a)
    for i in range(n):
        if a[i][n-1] == "1":
            a[i][n - 1] = "0"
            go(i, n-1)
    for i in range(n):
        if a[n-1][i] == "1":
            a[n - 1][i] = "0"
            go(n-1, i)
    done = False
    for i in range(n-1):
        if "1" in a[i]:
            print("NO")
            done = True
            break
    if not done:
        print("YES")