n = int(input())
a = [int(i) for i in input().split()]
m = int(input())
qs = [int(i) for i in input().split()]

cs = 0
pref_sums = []
for i in a:
    pref_sums.append(cs+i)
    cs += i

ans = []
for q in qs:
    l = -1
    r = n - 1
    while r - l > 1:
        m = l + (r - l) // 2
        if pref_sums[m] <= q:
            l = m
        else:
            r = m
    ans.append(r + 1)

print(*ans, sep='\n')

