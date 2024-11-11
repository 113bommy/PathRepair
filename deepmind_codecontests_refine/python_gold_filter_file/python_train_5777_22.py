if __name__ == '__main__':
    n = int(input())
    if 1 <= n <= 2:
        print(1, '\n1')
    elif n == 3:
        print(2, '\n1 3')
    elif n == 4:
        print(4, '\n3 1 4 2')
    else:
        print(n)
        print(' '.join(map(str, list(range(1, n + 1, 2)) + list(range(2, n + 1, 2)))))