import sys

def bin_search(c, k, rs):
    l, r = 0, k
    while l < r:
        mid = (l + r)//2
        if c == rs[mid][0]:
            return mid
        if c < rs[mid][0]:
            r = mid
        else:
            l = mid + 1
    return l

def solve(n, groups, k, rs):
    groups.sort(key = lambda x: (-x[2], x[1]))
    seated = [False for _ in rs]
    rs = sorted([(r, i + 1) for i, r in enumerate(rs)], key = lambda x: x[0])
    res = []
    total = 0
    for m, c, p in groups:
        index = bin_search(c, k, rs)
        while  0 < index and index < k and rs[index-1][0] == rs[index][0]:
            index -= 1
        while index < k and seated[index]:
            index += 1
        if index < k:
            res.append((m, index + 1))
            total += p
            seated[index] = True
    print("{} {}".format(len(res), total))
    for m, i in res:
        print("{} {}".format(m, i))
        

def main():
    n = int(input())
    groups = []
    for i in range(n):
        c, p = map(int, input().split())
        groups.append((i+1, c, p))
    k = int(input())
    rs = list(map(int, input().split()))
    solve(n, groups, k, rs)

if __name__ == "__main__":
    main()
