def prime(p):
    ret = {}
    a = int(p ** 0.5)
    k = 2
    while(p > 1):
        if p % k == 0:
            p //= k
            ret[k] = ret.get(k, 0) + 1
        elif k > a:
            k = p
        else:
            k += 1
    return ret


n, p = map(int, input().split())
ret = prime(p)
# print(ret)
ans = 1
for i in list(filter(lambda x: ret[x] >= n, list(ret))):
    ans *= i * (ret[i] // n)
print(ans)