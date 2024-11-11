def bit_add(arr, n, i, x):
    while i <= n:
        arr[i] += x
        i += i & -i

def bit_sum(arr, i):
    result = 0
    while i > 0:
        result += arr[i]
        i ^= i & -i
    return result

n, q = map(int, input().split())
color = [int(i) for i in input().split()]
query = []
rli = [0] * q
for i in range(q):
    l, r = map(int, input().split())
    query.append((l, r))
    rli[i] = (r << 40) + (l << 20) + i
rli.sort()
mask = (1 << 20) - 1
bn = n + 2
bit = [0] * (bn + 1)
ans = [0] * q
appeared = [-1] * (n + 1)
p = 0

for j in range(q):
    k = rli[j]
    r = k >> 40
    l = (k >> 20) & mask
    i = k & mask
    while p < r:
        c = color[p]
        before_appeared = appeared[c]
        if before_appeared != -1:
            bit_add(bit, bn, before_appeared + 2, -1)
        bit_add(bit, bn, p + 2, 1)
        appeared[c] = p
        p += 1
    ans[i] = bit_sum(bit, r + 1) - bit_sum(bit, l)
print('\n'.join(map(str, ans)))    