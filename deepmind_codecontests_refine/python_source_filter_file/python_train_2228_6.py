if __name__ == '__main__':
    n, m = [int(i) for i in input().split()]
    a_s = [int(i) for i in input().split()]

    a_s.sort()

    min_p = a_s[-1] - a_s[0]
    for i in range(len(a_s) - n):
        min_p = min(min_p, a_s[i + n - 1] - a_s[i])

    print(min_p)