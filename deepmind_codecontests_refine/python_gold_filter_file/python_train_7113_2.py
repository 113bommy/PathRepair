fsa = str(input()).split(" ")
n = int(fsa[0])
k = int(fsa[1])


def reduction(v, k, n):
    counter = 0
    nxt = v
    sm = 0
    while nxt > 0 and sm < n:
        sm += nxt
        #print(sm, nxt)
        counter += 1
        nxt = v // (k**counter )
    if sm < n:
        return -1
    return counter


def binarySearch(l, h, k, n):
    ans = -1

    while h >= l:
        m = l + abs(h - l) // 2
        #print("searching at", m)
        out = reduction(m, k, n)
        if out == -1:
            l = m + 1
        elif out > -1:
            ans = m
            h = m - 1
    return ans


print(binarySearch(1, n, k, n))
