def bin_value(v, X):
    return v & X

def sol():
    N, X = [int(x) for x in input().split(" ")]
    a = [int(x) for x in input().split(" ")]

    # check for duplicates
    d = {}
    b = {}

    # first pass checks for existing dups
    for i, v in enumerate(a):
        if v in d:
            return 0
        d[v] = i

    # second pass checks if conversion to binary
    # would collide
    # cases
    # collide with binary lower index = 1
    # collide with ten lower index = 2
    # collide with ten higher index = 1
    ans = 100
    for i, v in enumerate(a):
        binary = bin_value(v, X)

        if binary in d:
            index = d[binary]
            if i < index:
                ans = min(1, ans)
            elif i > index:
                ans = min(2, ans)

        if binary in b:
            index = b[binary]
            ans = min(1, ans)

        b[binary] = i

    return (-1 if (ans == 100) else ans)

ans = sol()
print(ans)
