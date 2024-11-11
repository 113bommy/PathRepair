def swap(a, i, j, verb=False):
    a[i], a[j] = a[j], a[i]
    if verb:
        i += 1
        j += 1
        print(min(i, j), max(i, j))

def cocktail_sort(a, verb=False):
    n = len(a)
    b = 0
    end = False
    while not end:
        end = True
        for i in range(b, n - b - 1):
            if a[i] > a[i + 1]:
                end = False
                swap(a, i, i + 1, verb)
        for i in range(n - b - 1, b, -1):
            if a[i] < a[i-1]:
                end = False
                swap(a, i-1, i, verb)
        b += 1

input()
a = list(map(int, input().split()))

cocktail_sort(a, True)
