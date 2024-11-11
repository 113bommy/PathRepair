n, k = map(int, input().split())
if k == 1:
    print(n)
else:
    j = 1
    while j * 2 - 1 < n:
        j *= 2
    print(j - 1)