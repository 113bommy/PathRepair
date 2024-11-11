def lavochki(n, m, lst):
    mx = max(lst) + m
    while m >= 0:
        ind = min(list(range(n)), key=lambda j: lst[j])
        lst[ind] += 1
        m -= 1
    return max(lst), mx


N = int(input())
M = int(input())
a = list()
for i in range(N):
    elem = int(input())
    a.append(elem)
print(*lavochki(N, M, a))
