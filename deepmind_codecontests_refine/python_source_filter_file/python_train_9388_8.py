from math import ceil


def main():
    t = int(input())
    for _ in range(t):
        n, cur = map(int, input().split())
        acc = []
        for _ in range(n):
            d, h = map(int, input().split())
            acc.append((h - d, d))

        dec_max = -min(acc)[0]
        dmax = max(acc, key=lambda x: x[1])[1]
        

        if dec_max <= 0 and cur > dmax:
            print(-1)
        elif dec_max <= 0 and cur <= dmax:
            print(0)
        else:
            steps = ceil((max(0, cur - dmax)) / dec_max) + 1
            print(steps)


if __name__ == "__main__":
    main()