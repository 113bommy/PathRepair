n, k, p, x, y = map(int, input().split())
a = list(map(int, input().split()))
t = 0  # кол-во чисел, меньших y
for i in a:
    if i < y:
        t += 1
m = (n+1)//2

if t >= m:
    print(-1)
else:
    ans = []
    ans += [y]*max(0, m-(k-t))
    k += m-(k-t)
    ans += [1]*max(0, n-k)
    if sum(ans)+sum(a) <= x:
        for i in ans[:-1]:
            print(i, end = ' ')
        print(ans[-1])
    else:
        print(-1)