N, *a = map(int, open(0).read().split())
ans = set()
over = 0
for v in a:
    v //= 400
    if v <8:
        ans.add(v)
    else:
        over += 1
print(len(ans), len(ans) + over)