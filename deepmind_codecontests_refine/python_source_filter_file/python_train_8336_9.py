def main():
    input()
    two, cnt, res = [1 << i for i in range(30, 0, -1)], {}, 0
    for a in map(int, input().split()):
        cnt[a] = cnt.get(a, 0) + 1
    for a, c in cnt.items():
        for t in two:
            b = t - a
            if b < 1:
                res += c
                break
            elif b in cnt:
                if a != b or c != 1:
                    break
    print(res)


if __name__ == '__main__':
    main()
