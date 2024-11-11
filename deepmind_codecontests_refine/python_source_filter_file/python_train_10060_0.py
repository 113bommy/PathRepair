if __name__ == '__main__':
    n = int(input())
    a = [0] * (n+1)
    a[0] = -(n + 5)
    k = list(map(int, input().split()))
    m = 0
    if n == 1:
        print(k[0])
        exit()
    for i in k:
        if i > m:
            a[i] = -1
            m = i
    m1 = m2 = 0
    for i in k:
        if m1 > i > m2:
            a[m1] += 1
            m2 = i
        if i > m1:
            m2 = m1
            m1 = i
    m = max(a)
    print(a)