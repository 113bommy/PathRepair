from collections import Counter


def main():
    H, W = map(int, input().split())
    A = [input() for _ in range(H)]
    space = {}
    space[1] = (H % 2) * (W % 2)
    space[2] = (H % 2) * (W//2*2) + (W % 2) * (H//2*2)
    space[4] = (H//2*2) * (W//2*2)
    cnt = Counter("".join(A))
    for alpha in cnt:
        c = cnt[alpha]
        for k in (4, 2, 1):
            while c//k >= 1 and space[k]:
                y = min(c//k, space[k])
                space[k] -= y
                c -= y * k
        if c:
            print("No")
            return
    print("Yes")


if __name__ == "__main__":
    main()
