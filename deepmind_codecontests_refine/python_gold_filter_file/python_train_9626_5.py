R = lambda: map(int, input().split())

n = int(input())
a = sorted(R()) + [int(2*10**9) + 1]
m = int(input())
b = sorted(R()) + [int(2*10**9) + 1]
i, j = 0, 0
ra, rb = n * 3, m * 3
if n * 2 - m * 2 > n * 3 - m * 3:
    ra, rb = n * 2, m * 2
while i < n or j < m:
    sa, sb = 0, 0
    if i <= n and j <= m and a[i] < b[j]:
        sa, sb = (i + 1) * 2 + (n - i - 1) * 3, j * 2 + (m - j) * 3
        i += 1
    elif i <= n and j <= m and a[i] > b[j]:
        sa, sb = i * 2 + (n - i) * 3, (j + 1) * 2 + (m - j - 1) * 3
        j += 1
    else:
        sa, sb = i * 2 + (n - i) * 3, j * 2 + (m - j) * 3
        i, j = i + 1, j + 1
    if (sa - sb == ra - rb and sa > ra) or sa - sb > ra - rb:
        ra, rb = sa, sb
print(str(ra) + ':' + str(rb))