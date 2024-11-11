INF = 10 ** 10
def merge(l, r):
    res = l + r
    
    i = j = k = 0
    while i < len(l) and j < len(r):
        if l[i] < r[j]:
            res[k] = l[i]
            k += 1
            i += 1
        else:
            res[k] = r[j]
            k += 1
            j += 1
    res[k + 1:] = l[i:] + r[j:]

    return res

def solve(fl, fr, l, r):
    if l == r:
        return 0
    
    mid = (l + r) // 2
    res = solve(fl, fr, l, mid) + solve(fl, fr, mid + 1, r)

    i, j = l, mid + 1
    while i <= mid:
        while j <= r and fr[j] < fl[i]:
            j += 1
        res += j - mid - 1
        i += 1
    fl[l: r + 1] = merge(fl[l: mid + 1], fl[mid + 1: r + 1])
    fr[l: r + 1] = merge(fr[l: mid + 1], fr[mid + 1: r + 1])
    return res

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))

    fl, cnt = [], {}
    for x in a:
        cnt[x] = cnt.get(x, 0) + 1
        fl.append(cnt[x])

    fr, cnt = [], {}
    for x in a[::-1]:
        cnt[x] = cnt.get(x, 0) + 1
        fr.append(cnt[x])
    fr = fr[::-1]

#     print(fl, fr)
    print(solve(fl, fr, 0, n - 1))
#     print(fl, fr)
