from sys import exit


def check_all(l, exclude):
    result = 0
    x, y = exclude
    for i in range(n):
        if i == x:
            continue
        s = sum(l[i])
        if not result:
            result = s
        elif s != result:
            return False, 0
    for j in range(n):
        if j == y:
            continue
        s = sum(row[j] for row in l)
        if s != result:
            return False, 0

    if x != y:
        s = sum(l[i][i] for i in range(n))
        if s != result:
            return False, 0
    if y != n - x - 1:
        s = sum(l[i][n - i - 1] for i in range(n))
        if s != result:
            return False, 0
    return True, result


n = int(input())

sq = []

zero_position = None

for i in range(n):
    row = list(map(int, input().split()))
    if not zero_position:
        if 0 in row:
            zero_position = (i, row.index(0))
    sq.append(row)

possible, s = check_all(sq, zero_position)

if not possible:
    print(-1)
else:
    x, y = zero_position
    result = s - sum(sq[x])
    number = s - sum(row[y] for row in sq)
    if number != result:
        print(-1)
        exit(0)
    if x == y:
        number = s - sum(sq[i][i] for i in range(n))
        if number != result:
            print(-1)
            exit(0)
    if y == n - x - 1:
        number = s - sum(sq[i][n-i-1] for i in range(n))
        if number != result:
            print(-1)
            exit(0)
    if n == 1:
        print(1)
    elif result >= 0:
        print(-1)
    else:
        print(result)
