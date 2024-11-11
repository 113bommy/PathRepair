n,m,k = map(int,input().split())


current = n*m - 1
if k < n:
    print (k+1,1)
else:
    remaining = k - n
    row_from_down = remaining // 2

    row = n - row_from_down
    # 11 10
    if row%2:
        col = remaining % (m-1)
        col = m - col

    else:
        col = remaining % (m-1)
        col += 2
    print (row, col)

