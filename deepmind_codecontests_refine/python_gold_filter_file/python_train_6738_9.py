n, k, l = map(int, input().split())
a = list(map(int, input().split()))

a.sort()

ub = n*k
for i in range(n*k):
    if a[i] - a[0] > l:
        ub = i
        break

if ub < n:
    print(0)
    exit(0)

res = 0
left = n
picked = [0] * (n*k)

for i in range(0, ub, k):
    res += a[i]
    picked[i] = 1
    left -= 1

i = ub - 1
while left > 0 and i >= 0:
    if picked[i] == 0:
        res += a[i]
        left -= 1

    i -= 1

assert(left == 0)
print(res)
