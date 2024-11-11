t = int(input())
k = 0
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    x = a[n - 1]
    j = n-2
    while j>0:
        if a[j] < x:
            x = a[j]
        else:
            k += 1
        j = j - 1
    print(k)
    k = 0