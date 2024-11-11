if __name__ == '__main__':
    q = int(input())
    l, r, i, j = dict(), dict(), -1, -1

    while q > 0:
        p, k = input().split()
        if p == "L":
            i += 1
            l[k] = l.get(k, i)
        elif p == "R":
            j += 1
            r[k] = r.get(k, j)
        else:
            if l.get(k, -1) >= 0:
                if i - l.get(k) <= j + l.get(k) + 1:
                    print(i - l.get(k))
                else:
                    print(j + l.get(k) + 1)
            else:
                if j - r.get(k) <= i + r.get(k) + 1:
                    print(j - r.get(k))
                else:
                    print(i + r.get(k) + 1)
        q -= 1