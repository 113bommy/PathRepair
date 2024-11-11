def read(datatype=int):
    return datatype(input())


def readl(datatype=int):
    return list(map(datatype, input().split()))


def printl(data):
    string = ''
    for d in data:
        string += str(d) + ' '
    print(string)


def testcase():

    # --------------------- start testcase ---------------------

    n, x, y = readl()

    x, y = max(x, y), min(x, y)
    arr = [0 for _ in range(n)]


    best_diff = 1
    best_max = 10 ** 9
    best_start = 1

    for diff in range(1, x - y + 1):

        if (x - y) % diff == 0:
            alpha = (x - y) // diff
            if alpha >= n:
                continue
            elif alpha == n - 1:
                best_diff = diff
                best_start = y
                break
            else:
                left = (y - 1) // diff
                if alpha + left >= n:
                    best_max = x
                    best_diff = diff
                    best_start = y - diff * (n - alpha - 1)
                    break
                else:
                    right = n - alpha - left
                    curr_max = x + diff * right
                    curr_start = y - diff * (n - alpha - right)
                    if curr_max < best_max:
                        best_diff = diff
                        best_max = curr_max
                        best_start = curr_start
    #print('best start, diff', best_start, best_diff)
    arr = [best_start]
    for _ in range(n - 1):
        arr.append(arr[-1] + best_diff)

    printl(arr)



    # --------------------- end testcase -----------------------
    return


t = read()
for _ in range(t):
    testcase()
