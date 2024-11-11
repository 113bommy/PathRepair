def ascending_until(l):
    for k, e in enumerate(l):
        if k + l[0] != e:
            return k

    return len(l)


def descending_until(l):
    for k, e in enumerate(reversed(l)):
        if l[-1] - k != e:
            return len(l) - k

    return 0


if __name__ == '__main__':
    n = int(input())
    order = list(map(int, input().split()))

    i = ascending_until(order)
    if i == len(order):
        print(0, 0)
    else:
        j = descending_until(order)
        order[i:j] = list(reversed(order[i:j]))
        if ascending_until(order) == len(order):
            print(order[i], order[j - 1])
        else:
            print(0, 0)
