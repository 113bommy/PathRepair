def almost(n, d):
    d = sorted(d)
    result = d[0] * d[-1]
    div = []
    for i in range(2, int(n**0.5) + 1):
        if result % i == 0:
            if result // i == i:
                div.append(i)
            else:
                div.append(i)
                div.append(result // i)
    div = sorted(div)

    return result if d != div else -1


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        d = [int(item) for item in input().split()]
        print(almost(n, d))
