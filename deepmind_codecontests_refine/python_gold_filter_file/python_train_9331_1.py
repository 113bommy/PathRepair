if __name__ == '__main__':
    a, b = [int(i) for i in input().strip().split()]
    y, g, bl = [int(i) for i in input().strip().split()]
    ry = y * 2 + g
    rb = bl * 3 + g
    ans = 0
    if ry > a:
        ans += abs(ry - a)
    if rb > b:
        ans += abs(rb - b)
    print(ans)
