from sys import stdin

def input():
    return next(stdin)

def main():
    def solve():

        ss = input()
        count = 0
        l = 0
        sums = {}
        count = 0
        last1 = -1
        for r in range(len(ss)):
            d = 1 if ss[r] == '1' else 0
            if d == 1:
                sums[(last1+1, r)] = 0
                last1 = r
            for (ll, lr),v in list(sums.items()):
                v += v + d
                if v > r -ll + 1:
                    del sums[(ll,lr)]
                else:
                    if v <= r -ll + 1 and v >= r -lr + 1:
                        count += 1
                    sums[(ll,lr)] = v
        print(count)


    q = int(input())
    for _ in range(q):
        solve()


if __name__ == "__main__":
    main()