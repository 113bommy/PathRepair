# problem on code forces
# https://codeforces.com/problemset/problem/1082/A

t = int(input())

for i in range(t):
    inp = input().split()
    n = int(inp[0])
    x = int(inp[1])
    y = int(inp[2])
    d = int(inp[3])

    check = [-1, -1, -1]

    # check going directly
    if (y-x) % d == 0:
        check[0] = abs(int((y-x) / d))

    # check moving to page 1 first
    if (y-1) % d == 0:
        if (x-1) % d == 0:
            count = int((x-1) / d)
        else:
            count = int((x-1) / d)
            count += 1
        count += int((y-1) / d)
        check[1] = count

    # check moving to last page first
    if (n-y) % d == 0:
        if (n - x) % d == 0:
            count = int((n - x) / d)
        else:
            count = int((n - x) / d)
            count += 1
        count += int((n - y) / d)
        check[2] = count

    min_moves = -1

    for j in check:
        if j > 0:
            if min_moves == -1:
                min_moves = j
            elif j < min_moves:
                    min_moves = j

    print(min_moves)
