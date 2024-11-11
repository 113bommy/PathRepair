if __name__ == '__main__':
    cin = input
    n, a, b = map(int, cin().split())
    p = [int(i) for i in cin().split()]
    cnt, c = 0, 0

    for t in p:
        if t == 1:
            if a: a -= 1
            elif b:
                b -= 1
                c += 1
            elif c:
                c -= 1
            else: cnt += t
        else:
            if b > 1: b -= 2
            else: cnt += t
    print(cnt)
