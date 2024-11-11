if __name__ == '__main__':
    n = int(input())
    line = list(map(int, input().split()))
    p, v = 0, 1000
    for i in range(n):
        t = abs(line[i] - line[(i + 1) % n])
        if v > t:
            v = t
            p = i
    print(str(p) + ' ' + str((p + 1) % n))
