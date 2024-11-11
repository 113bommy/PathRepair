def main():
    n = int(input())
    l = [0, 0, 0, 0]
    for _ in range(n):
        x, y = map(int, input().split())
        l[(x & 1) * 2 + (y & 1)] += 1
    _, x, y, z = l
    x += y
    if x & 1:
        print(-1)
    elif x:
        print((y + z) & 1)
    else:
        print(0)


if __name__ == '__main__':
    main()
