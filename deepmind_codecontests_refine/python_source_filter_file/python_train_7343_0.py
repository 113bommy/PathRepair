n = int(input())
tab = list(map(int, input().split()))


for i in range(n):
    for j in range(i, n - 1):
        if tab[j] > tab[j + 1]:
            tab[j], tab[j + 1] = tab[j + 1], tab[j]
            print(str(j + 1) + " " + str(j + 2))
