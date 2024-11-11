for _ in range(int(input())):
    l, r = map(int, input().split())
    print(['-1 -1', f'{l} {2 * l}'][2 * l <= r])
    