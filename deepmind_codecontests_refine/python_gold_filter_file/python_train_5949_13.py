n, m, k = map(int, input().split())
tab = map(int, input().split())
tab = [(t,i) for i, t in enumerate(tab)]
tab.sort()
want = [False for _ in range(n)]
for _, i in tab[n - k*m:]:
    want[i] = True
counter = 0
print(sum((t for t, i in tab if want[i])))
printed = 0
for i, w in enumerate(want):
    counter += w
    if counter == m:
        if i+1 != n:
            print(i+1, end=' ')
            printed += 1
        counter = 0
    if printed == k - 1:
        break
