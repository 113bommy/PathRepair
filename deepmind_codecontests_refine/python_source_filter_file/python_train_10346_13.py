n , k = input().split(' ')
n = int(n)
k = int(k)
ans = -99999999
for i in range(n):
    c = [int(i) for i in input().split(' ')]
    if c[1] > k:
        ans = max(ans, c[0] - (c[1] - k))
    else:
        ans = max(ans, c[0])
print(ans)

