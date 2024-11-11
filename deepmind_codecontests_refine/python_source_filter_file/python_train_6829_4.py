def read_tokens():
    return input().strip().split(' ')


def read_ints():
    return [int(s) for s in read_tokens()]


n, k = read_ints()


def solve(n, k):
    prizer = n // 2
    if prizer // k == 0:
        print(0, 0, n)
        return

    bad = 1
    good = max(n,k)
    while good - bad > 1:
        diploma = (good + bad) // 2
        if diploma * k + diploma >= prizer:
            good = diploma
        else:
            bad = diploma

    if good + good*k == prizer:
        print(good, good*k, n - good - good*k)
        return 
    print(bad, bad * k, n - bad - bad*k)


solve(n, k)
