if __name__ == '__main__':
    x = input().split()
    z = input().split()
    l = []
    for i in range(len(z)):
        l.append(int(z[i]))
    y = input().split()
    m = []
    for i in range(len(y)):
        m.append(int(y[i]))
    n = j = 0
    for i in range(len(l)):
        if m[j] >= l[i]:
            n += 1
            j += 1
        if j == len(m):
            break
    print(n)