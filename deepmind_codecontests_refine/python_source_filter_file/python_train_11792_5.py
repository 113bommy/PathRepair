T = int(input())
for _ in range(T):
    n, k = map(int, input().split())
    l1, r1 = map(int, input().split())
    l2, r2 = map(int, input().split())
    ans = 0
    if k <= 0:
        print(0)
    elif l1 >= l2 and r1 <= r2:
        k -= (r1 - l1) * n
        if k <= 0:
            print(0)
        else:
            trans = n * (l1 - l2 + r2 - r1)
            ans += min(k, n * trans)
            k -= trans
            print(ans if k <= 0 else ans + 2 * k)
    elif l2 >= l1 and r2 <= r1:
        k -= (r2 - l2) * n
        if k <= 0:
            print(0)
        else:
            trans = n * (l2 - l1 + r1 - r2)
            ans += min(k, trans)
            k -= trans
            print(ans if k <= 0 else ans + 2 * k)
    elif r2 <= l1:
        ans += l1 - r2
        trans = r1 - l2
        ans += min(k, trans)
        k -= trans
        if k <= 0:
            print(ans)
        else:
            for i in range(2, n + 1):
                t1 = l1 - r2 + min(k, r1 - l2)
                ans += min(t1, 2 * min(k, r1 - l2))
                k -= min(k, r1 - l2)
                if k <= 0:
                    break
            print(ans if k <= 0 else ans + 2 * k)
    elif l2 >= r1:
        ans += l2 - r1
        trans = r2 - l1
        ans += min(k, trans)
        k -= trans
        if k <= 0:
            print(ans)
        else:
            for i in range(2, n + 1):
                t1 = l2 - r1 + min(k, r2 - l1)
                ans += min(t1, 2 * min(k, r2 - l1))
                k -= min(k, r2 - l1)
                if k <= 0:
                    break
            print(ans if k <= 0 else ans + 2 * k)
    else:
        if l1 > l2 or (l1 == l2 and r1 > r2):
            l1, l2 = l2, l1
            r1, r2 = r2, r1
        k -= n * (r1 - l2)
        if k <= 0:
            print(0)
        else:
            trans = n * (abs(r2 - r1) + abs(l2 - l1))
            ans += min(k, trans)
            k -= trans
            print(ans if k <= 0 else ans + 2 * k)
