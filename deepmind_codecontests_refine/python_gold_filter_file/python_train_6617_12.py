n, n1, n2 = map(int, input().split())
a = sorted(map(float, input().split()), reverse=True)

ans = 0
if n1 > n2:
    ans = (sum(a[:n2]) * n1 + sum(a[n2:n1+n2]) * n2) / (n1 * n2)
else:
    ans = (sum(a[:n1]) * n2 + sum(a[n1:n1+n2]) * n1) / (n1 * n2)

print('{:0.8f}'.format(ans))