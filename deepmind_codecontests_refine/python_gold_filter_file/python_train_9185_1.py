def bs(a):
    low = 0
    high = len(li) - 1
    while low <= high:
        if high - low < 5:
            for i in range(low, high+1):
                if li[i] >= a:
                    return i
            return 0
        mid = (low + high) // 2
        if li[mid] >= a:
            high = mid
        else:
            low = mid + 1


def bs2(a):
    low = 0
    high = len(l) - 1
    while low <= high:
        if high - low < 5:
            for i in range(low, high+1):
                if l[i] > a:
                    return len(l) - i
            return 0
        mid = (low + high) // 2
        if l[mid] > a:
            high = mid
        else:
            low = mid+1


t = int(input())
for _ in range(t):
    n, k = [int(x) for x in input().split()]
    s = list(map(int, input().split()))
    l = []
    li = []
    sum = []
    dict = {}
    for i in range(n // 2):
        l.append(min(s[i], s[n - 1 - i]))
        li.append(max(s[i], s[n - 1 - i]))
        if dict.get(s[i] + s[n - 1 - i]) is None:
            dict[s[i] + s[n - 1 - i]] = 0
        dict[s[i] + s[n - 1 - i]] += 1
    for x in dict.keys():
        sum.append((x, dict[x]))
    l.sort()
    li.sort()
    ans = n // 2
    for p in sum:
        x = 0
        y = 0
        if p[0] > k:
            x = p[0] - k
            y = k
            z = bs(x)
            ans = min(ans, (2 * z) + (n // 2) - z - p[1])
        else:
            x = 1
            y = p[0] - 1
            z = bs2(y)
            ans = min(ans, 2 * z + (n // 2) - z - p[1])
    print(ans)
