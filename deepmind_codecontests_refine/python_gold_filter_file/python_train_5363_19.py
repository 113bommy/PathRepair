
def calc_splits(n, q, p):
    max_q = int(n/q) + 1
    max_p = int(n/p) + 1

    for k in range(0, max_q):
        value = q * k
        if (n - value) % p == 0:
            return (k, q, int((n - value) / p), p)

    for i in range(0, max_p):
        value = p * i
        if (n - value) % q == 0:
            return (k, p, int((n - value) / q), q)

    return -1

if __name__ == "__main__":



    _in = input()
    n, p, q = _in.split(" ")
    n, p, q = int(n), int(p), int(q)

    string = input()
    value = calc_splits(n, p, q)

    if value == -1:
        print(-1)
    else:
        k1, v1, k2, v2 = value
        print(k1 + k2)
        #print(value)
        counter = 0
        for i in range(1, k1 + k2 + 1):
            if i <= k1:
                print(string[counter: counter + v1])
                counter += v1
            else:
                print(string[counter : counter + v2])
                counter += v2

