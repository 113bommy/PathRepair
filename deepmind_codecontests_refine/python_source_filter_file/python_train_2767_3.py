if __name__ == '__main__':
    refer = (
        (1, 0, 2),
        (1, 2, 0),
        (2, 1, 0),
        (2, 0, 1),
        (0, 2, 1),
        (0, 1, 2),
    )
    n = int(input())
    x = int(input())
    print(refer[n % 6][x])
