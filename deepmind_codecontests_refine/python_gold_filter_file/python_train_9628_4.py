n, k = map(int, input().split())
if n % 2 == 0:
    if k <= n * n // 2:
        print("YES")
        table = [["S" for i in range(n)] for j in range(n)]
        i, j = 0, 0
        while k > 0:
            table[i][j] = "L"
            k -= 1
            if i + 2 < n:
                i += 2
            else:
                j += 1
                if j % 2 == 0:
                    i = 0
                else:
                    i = 1
        for i in range(n):
            for j in range(n):
                print(table[i][j], end = '')
            print()
    else:
        print("NO")
else:
    if k <= n // 2 + 1 + (n - 1) // 2 * n:
        print("YES")
        table = [["S" for i in range(n)] for j in range(n)]
        i, j = 0, 0
        while k > 0:
            k -= 1
            table[i][j] = "L"
            if i + 2 < n:
                i += 2
            else:
                j += 1
                if j % 2 == 0:
                    i = 0
                else:
                    i = 1
        for i in range(n):
            for j in range(n):
                print(table[i][j], end = '')
            print()
    else:
        print("NO")