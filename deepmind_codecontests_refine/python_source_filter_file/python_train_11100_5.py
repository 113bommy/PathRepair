g, f = map(int, input().split())
mas = list(map(int, input().split()))
k = max(mas)
q = 0
n = mas[0]
for i in range(g):
    if mas[i] == k:
        print(mas[i])
        break
    if mas[i] > n:
        n = mas[i]
        q = 0
    else:
        if i != 0:
            q += 1
    if q == f:
        print(n)
        break