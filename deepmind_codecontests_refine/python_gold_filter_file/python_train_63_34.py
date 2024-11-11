n, k = map(int, input().split())
l = sorted(list(map(int, input().split())))
for i in range(n - 1, -1, -1):
    if k % l[i] == 0:
        print(k // l[i])
        break