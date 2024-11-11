
def solve(n, k, msgs):
    sc_dic = {}
    sc = []

    for m in msgs:
        if m not in sc_dic:
            sc_dic[m] = 1
            sc.append(m)
        if len(sc) > k:
            sc_dic.pop(sc.pop(-1))

    sc = sc[::-1]
    print(len(sc))
    for a in sc:
        print(a, end=" ")


def main():
    n, k = map(int, input().split())
    msgs = list(map(int, input().split()))

    solve(n, k, msgs)


if __name__ == "__main__":
    main()