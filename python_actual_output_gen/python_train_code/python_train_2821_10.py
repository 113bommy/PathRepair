
if __name__ == "__main__":
    n, h, a, b, k = map(int, input().split())

    for i in range(k):
        ta, fa, tb, fb = map(int, input().split())
        if ta == tb:
            print(abs(fa - fb))
            continue

        res = abs(ta - tb) + abs(fa - fb)

        if fa > b and fb > b:
            res += 2 * (min(fa, fb) - b)

        if fa < a and fa < a:
            res += 2 * (a - max(fa, fb))

        print(res)