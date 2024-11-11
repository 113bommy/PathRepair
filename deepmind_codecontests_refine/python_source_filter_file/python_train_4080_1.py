from itertools import islice

if __name__ == '__main__':
    _, k = tuple(map(int, input().split()))
    arr = list(map(int, input().split()))

    counts = [None] * (2 * (10 ** 5) + 1)

    def append_counts(xx, cnt):
        if counts[xx] is None:
            counts[xx] = []
        counts[xx].append(cnt)

    for a in arr:
        cur = 0
        x = a

        while x > 0:
            append_counts(x, cur)
            x //= 2
            cur += 1

    result = 2 * (10 ** 6)
    for i in counts:
        if i and len(i) >= k:
            i.sort()
            result = min(result, sum(islice(i, 0, k)))

    print(result)




