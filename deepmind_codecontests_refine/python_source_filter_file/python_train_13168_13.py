from collections import defaultdict


def main():
    n, s = map(int, input().split())
    sell, buy = defaultdict(lambda: 0), defaultdict(lambda: 0)
    for _ in range(n):
        d, p, q = input().split()
        if d[0] == 'S':
            sell[int(p)] += int(q)
        else:
            buy[int(p)] += int(q)
    for key in sorted(sell.keys())[s::-1]:
        print('S {0} {1}'.format(key, sell[key]))

    for key in sorted(buy.keys())[::-1][:s]:
        print('B {0} {1}'.format(key, buy[key]))


if __name__ == '__main__':
    main()
