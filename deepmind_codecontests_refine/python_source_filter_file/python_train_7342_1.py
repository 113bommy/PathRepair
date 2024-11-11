def main():
    from collections import Counter
    n = int(input())
    cnt, res = dict(Counter(map(int, input().split()))), []
    if cnt.get(0, 0) * 2 >= n:
        print([0])
        return
    cget, rpush = cnt.get, res.append

    def deeper(a, b, lvl):
        if cget(a + b, 0):
            c = a + b
            cnt[c] -= 1
            deeper(b, c, lvl + 1)
            cnt[c] += 1
        else:
            rpush(lvl)

    for x in cnt:
        cnt[x] -= 1
        for y in cnt:
            if cnt[y]:
                cnt[y] -= 1
                deeper(x, y, 2)
                cnt[y] += 1
        cnt[x] += 1
    print(max(res))


if __name__ == '__main__':
    main()
