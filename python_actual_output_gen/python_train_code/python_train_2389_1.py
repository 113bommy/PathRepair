import sys
input = sys.stdin.readline


def read_int():
    return int(input().strip())


def read_ints():
    return list(map(int, input().strip().split(' ')))


def solve():
    """
    4 4

    4 3 1 6

    3 2 4 5

    3 2 5 4
    """
    n, x = read_ints()
    a = read_ints()
    last_min_j = x%n
    for j in range(x, x+n):
        if a[j%n] <= a[last_min_j]:
            last_min_j = j%n
    temp = a[last_min_j]
    a[last_min_j] += n*temp
    a = [a0-temp for a0 in a]
    j = last_min_j
    while j%n != x-1:
        a[j%n] -= 1
        j += 1
        a[last_min_j] += 1
    print(*a)


if __name__ == '__main__':
    solve()
