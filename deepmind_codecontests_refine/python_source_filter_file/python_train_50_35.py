def main():
    [n, m] = [int(_) for _ in input().split()]
    marked = [True] + ([False] * m)

    for _ in range(n):
        bulbs = [int(_) for _ in input().split()]

        for b in bulbs:
            marked[b] = True

    print('NO' if False in marked else 'YES')


if __name__ == '__main__':
    main()
