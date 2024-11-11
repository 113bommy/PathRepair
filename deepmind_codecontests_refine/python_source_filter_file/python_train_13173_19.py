from math import ceil


def main():
    n,m = [int(v) for v in input().split()]
    vals = [input() for v in range(m)]
    vals.append('1'*n)
    m = 0
    l = 0
    for i, v in enumerate(vals):
        if v == '1'*n:
            m = max(i-l-1, m)
            l = i
    print(m)


if __name__ == "__main__":
    main()
