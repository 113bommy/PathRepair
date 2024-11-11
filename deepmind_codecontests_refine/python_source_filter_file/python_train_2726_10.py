if __name__ == '__main__':
    h, w = map(int, input().split(' '))
    r = list(map(int, input().split(' ')))
    c = list(map(int, input().split(' ')))

    grid = [[0]*w for _ in range(h)]

    s = h*w
    invalid = False

    for i in range(h):
        j = 0
        while j < r[i]:
            if grid[i][j] == 0:
                grid[i][j] = 1
                s -= 1
            j += 1
        if j < w:
            if grid[i][j] == 0:
                grid[i][j] = 2
                s -= 1
            elif grid[i][j] == 1:
                invalid = True
                break

    if not invalid:
        for j in range(w):
            i = 0
            while i < c[j]:
                if grid[i][j] == 0:
                    grid[i][j] = 1
                    s -= 1
                elif grid[i][j] == 2:
                    invalid = True
                    break
                i += 1
            if not invalid and i < h:
                if grid[i][j] == 0:
                    grid[i][j] = 2
                    s -= 1
                elif grid[i][j] == 1:
                    invalid = True
                    break

            if invalid:
                break

    q = 1000000007

    if invalid:
        print(0)
    elif s <= 0:
        print(0)
    else:
        ans = 1
        for i in range(s):
            ans = (ans*2) % q
        print(ans)

