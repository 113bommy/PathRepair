if __name__ == '__main__':
    k, p = map(int, input().split())
    s = 0
    for i in range(k):
        sr = str(i)
        r = sr[::-1]
        s += int(sr + r)
    print(s % p)