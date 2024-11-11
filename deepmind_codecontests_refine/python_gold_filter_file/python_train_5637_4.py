def parse():
    input()
    sizes = list(map(int, input().split()))
    return sizes


def main():
    sizes = parse()
    combs = {}
    for i in range(len(sizes)):
        for j in range(i + 1, len(sizes)):
            s = sizes[i] + sizes[j]
            if s in combs:
                combs[s] += 1
            else:
                combs[s] = 1
    best = 0
    for v in combs.keys():
        if combs[v] > best:
            best = combs[v]
    print(best)


if __name__ == "__main__":
    main()