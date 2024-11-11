n, m = list(map(int, input().split()))
cnt = 0
l = n
while l < m:
    cnt += 1
    l *= 2
dif = l - m
val = 2 ** cnt
while dif > 0:
    cnt += dif // val
    dif %= val
    val /= 2
print(cnt)

