def main():
    n, s = map(int, input().split())
    tot = {"S": {}, "B": {}}
    for _ in range(n):
        tmp = input().split()
        t, p, q = tot[tmp[0]], int(tmp[1]), int(tmp[2])
        t[p] = t.get(p, 0) + q
    for c in "S", "B":
        t = tot[c]
        pp = sorted(t.keys(), reverse=True)
        for p in pp[-2:] if c == "S"  else pp[:2]:
            print(c, p, t[p])


if __name__ == '__main__':
    main()
