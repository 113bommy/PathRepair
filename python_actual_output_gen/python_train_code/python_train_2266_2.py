N, P = map(int, input().split())
A = map(int, input().split())

n_even = len(list(filter(lambda x: x % 2 == 0, A)))
n_odd = N - n_even
ans = 2 ** max(0, n_odd - 1) * 2 ** n_even
if P == 0 and n_odd == 0:
    print(0)
else:
    print(ans)
