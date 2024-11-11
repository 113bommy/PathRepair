n = int(input())
a = list(map(int, input().split()))

if n == 1:
    print(a[0])
    exit()

b = list(sorted(set(a)))

def count_inversion(ans):
    s = [0 for _ in range(2 * n) + 2]

    def bit_add(i):
        x = i
        while x < 2 * n:
            s[x] += 1
            x += x & -x

    def bit_sum(i):
        x = i
        ret = 0
        while x > 0:
            ret += s[x]
            x -= x & -x
        return ret

    temp = [n for _ in range(n + 1)]
    temp[0] = n + 1
    for i in range(n):
        if a[i] >= b[ans]:
            temp[i + 1] = temp[i] + 1
        else:
            temp[i + 1] = temp[i] - 1
    res = 0
    for i in range(n + 1):
        x = temp[i]
        res += bit_sum(x)
        bit_add(x)
    return res

m = n * (n + 1) // 2

ans = 0

l = 0
r = len(b)
while 1:
    ans = (l + r) // 2
    if count_inversion(ans) * 2 >= m:
        l = ans
    else:
        r = ans
    if r - l <= 1:
        ans = l
        break

print(b[ans])
