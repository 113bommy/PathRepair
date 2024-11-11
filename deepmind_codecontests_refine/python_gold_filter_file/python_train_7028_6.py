from functools import reduce

if __name__ == '__main__':
    n = int(input())
    line = list(map(int, input().split()))
    rest = list()
    for i in range(n):
        if line[i] == 1:
            rest.append(i + 1)
    size = len(rest)
    if size < 2:
        print(size)
    else:
        for i in range(1, size):
            rest[i - 1] = rest[i] - rest[i - 1]
        print(reduce(lambda x, y: x * y, rest[:-1]))
