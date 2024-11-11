N = int(input())
a = list(map(int, input().split()))

maxa = max(a)
mina = min(a)
add = None
if abs(maxa) > abs(mina):
    add = maxa
else:
    add = mina

index = a.index(add)
ans = [(index, i) for i in range(N) if i != index]
if add > 0:
    ans += [(i, i+1) for i in range(N-1)]
else:
    ans += [(i, i-1) for i in range(N-1, 1, -1)]

ans = list(map(lambda x: (x[0]+1, x[1]+1), ans))
print(len(ans))
print('\n'.join(map(lambda x: '%d %d' % x, ans)))
