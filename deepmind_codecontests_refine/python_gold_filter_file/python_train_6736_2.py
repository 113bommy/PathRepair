t = input().split(" ")
t = [int(e) for e in t]

(n, k, l) = t


big = input().split(" ")
big = [int(e) for e in big]

assert len(big) == n * k

big.sort()


def getResult(n, k, l, big):
    if big[n-1] - big[0] > l:
        return 0

    right = None
    for (i, e) in enumerate(big):
        if e - big[0] > l:
            right = i
            break
    if right == None:
        right = len(big)

    n_fei = right - n

    result = 0

    i = 0
    for todo in range(n):
        result += big[i]

        if n_fei >= k - 1:
            i += k
            n_fei -= k-1
        else:
            i += n_fei + 1
            n_fei -= n_fei

    return result








result = getResult(n, k, l, big)
print(result)
