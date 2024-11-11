def main():
    n = int(input())
    m = [int(x) for x in input().split()]

    i = 0
    max_elem = -1
    while i < n:
        delta = m[i] - max_elem
        if delta > 1:
            return i + 1
        if delta == 1:
            max_elem += 1
        i += 1
    return -1


if __name__ == '__main__':
    res = main()
    print(res)