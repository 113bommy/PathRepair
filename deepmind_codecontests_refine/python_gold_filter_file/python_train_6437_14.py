def solve(string):
    l = [s == "1" for s in string]
    l_r = l[::-1]
    index = 0
    h = len(string) // 2
    for i, (c, n, c_r, n_r) in enumerate(zip(l[:h], l[1:h + 1], l_r[:h], l_r[1:h + 1])):
        if c ^ n or c_r ^ n_r:
            index = i + 1
    return str(len(string) - index)


if __name__ == '__main__':
    print(solve(input()))
