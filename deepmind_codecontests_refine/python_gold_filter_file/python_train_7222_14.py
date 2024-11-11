grid = [input(), input(), input(), input()]
slice_x = 2
slice_y = 2
def test_slice():
    width = 4
    height = 4
    slices = []
    for i in range(0, height - slice_y + 1):
        for j in range(0, width - slice_x + 1):
            slices.append(
                [
                    [grid[a][b] for b in range(j, j + slice_x)]
                    for a in range(i, i + slice_y)
                ]
            )
    return slices


if __name__ == "__main__":
    slices = test_slice()
    for sl in slices:
        hashCounter = 0
        dotCounter = 0
        for i in sl:
            hashCounter += i.count('#')
            dotCounter += i.count('.')
        if hashCounter >= 3 or dotCounter >= 3:
            print("YES")
            exit()
    print('NO')

