def Bin(li, x):
    i = 0
    j = len(li)-1
    while i < j:
        m = int((i+j)/2)
        if x > li[m]:
            i = m+1
        else:
            j = m
    return j


def intpolsearch(values, x):
    idx0 = 0
    idxn = (len(values) - 1)
    while (idx0 <= idxn and x >= values[idx0] and x <= values[idxn]):
        mid = idx0 + int(((float(idxn - idx0)/( values[idxn] - values[idx0]))*(x - values[idx0])))

        if ((values[mid] < x and values[mid + 1] > x) or values[mid] == x):
            return mid + 1

        if values[mid] < x:
            idx0 = mid + 1


def G():
    n = 100000
    a = [i for i in range(n + 1)]
    a[0] = 0
    lst = []

    i = 2
    while i <= n:
        if a[i] != 0:
            lst.append(a[i])
        for j in range(i, n + 1, i):
            a[j] = 0
        i += 1

    data = input().split()
    n, m = int(data[0]), int(data[1])

    matrix = []

    sum_j = [0 for i in range(m)]

    summ = 999999999999

    for i in range(n):
        s = input().split()
        now = []
        for j in range(m):
            if int(s[j]) == 1:
                el = 1
            else:
                k = Bin(lst, int(s[j]))
                el = lst[k] - int(s[j])
            now.append(el)
            sum_j[j] += el
        matrix.append(now)

        ns = sum(now)

        if ns < summ:
            summ = ns

    min_j = min(sum_j)
    if min_j < summ:
        print(min_j)
    else:
        print(summ)


if __name__ == "__main__":
    G()