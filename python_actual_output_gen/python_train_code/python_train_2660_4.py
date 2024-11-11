def check(x):
    num = {}
    d = {}
    for i in st:
        num[i] = 0
        d[i] = 1
    m = len(num.values())
    for j in range(x):
        num[st[j]] += 1
        d[st[j]] = 0
    i = x
    j = 0
    if sum(d.values()) == 0:
        return True
    while i < n:
        num[st[j]] -= 1
        if num[st[j]] <= 0:
            d[st[j]] = 1
        num[st[i]] += 1
        d[st[i]] = 0
        if sum(d.values()) == 0:
            return True 
        i += 1
        j += 1
    return False

def binary(p, q):
    if p >= q:
        return q
    mid = (p + q) // 2
    if check(mid):
        return binary(p, mid - 1)
    else:
        return binary(mid + 1, q)

n = int(input())
st = input()
ans = binary(1, n)
print(ans if check(ans) else ans + 1)


