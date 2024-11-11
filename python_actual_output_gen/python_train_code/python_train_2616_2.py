def solve():
    n, m = list(map(int, input().split(" ")))
    arr = []

    for i in range(n):
        arr.append(list(map(int, input().split(" "))))

    total = 0
    for row_index in range(n-1, -1, -1):
        col_index = m - 1

        while col_index > 0:
            if arr[row_index][col_index] == 0:
                arr[row_index][col_index] = min(arr[row_index + 1][col_index], arr[row_index][col_index + 1]) - 1
            
            if arr[row_index][col_index] <= arr[row_index][col_index - 1]:
                print("-1")
                return
            col_index -= 1

        total += sum(arr[row_index])

    for col in range(m-1, -1, -1):
        for row in range(n-1, 0, -1):
            if arr[row][col] < arr[row-1][col]:
                print("-1")
                return


    print(total)
solve()
