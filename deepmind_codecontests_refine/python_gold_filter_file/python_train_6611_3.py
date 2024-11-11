def first(s):
    return next(iter(s))


def invert(n, fs, bs):
    finv = [set() for _ in range(n)]
    for i, fi in enumerate(fs):
        finv[fi-1].add(i)

    ambiguous = False
    as_ = []
    for b in bs:
        s = finv[b-1]
        if not s:
            return "Impossible", None
        if len(s) > 1:
            ambiguous = True
        as_.append(first(s)+1)
    return "Ambiguity" if ambiguous else "Possible", as_


if __name__ == '__main__':
    n, m = map(int, input().split())
    fs = tuple(map(int, input().split()))
    bs = tuple(map(int, input().split()))
    result, seq = invert(n, fs, bs)
    print(result)
    if result == 'Possible':
        print(' '.join(map(str, seq)))
