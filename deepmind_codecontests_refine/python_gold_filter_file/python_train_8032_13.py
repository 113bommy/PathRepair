n, m = tuple(map(int, input().rstrip().split()))

a = []

for i in range(0, n):
    row = list(input())
    a .append(row)


def cross(a):
    cross_found = False

    for i in range(0, n):
        for j in range(0, m):
            if a[i][j] == '.':
                pass
            elif 0 < i < n - 1 and 0 < j < m - 1 \
                    and a[i][j] == '*' \
                    and a[i - 1][j] == '*' \
                    and a[i + 1][j] == '*' \
                    and a[i][j - 1] == '*' \
                    and a[i][j + 1] == '*':
                if cross_found:
                    return 'NO'

                cross_found = True

                k = j

                while 0 <= k < m and a[i][k] == '*':
                    a[i][k] = 'X'
                    k += 1

                k = j - 1

                while 0 <= k < m and a[i][k] == '*':
                    a[i][k] = 'X'
                    k -= 1

                k = i + 1

                while 0 <= k < n and a[k][j] == '*':
                    a[k][j] = 'X'
                    k += 1

                k = i - 1

                while 0 <= k < n and a[k][j] == '*':
                    a[k][j] = 'X'
                    k -= 1

            else:
                pass

    for i in range(0, n):
        for j in range(0, m):
            if a[i][j] == '*':
                return 'NO'

    if cross_found:
        return 'YES'
    else:
        return 'NO'


print(cross(a))
