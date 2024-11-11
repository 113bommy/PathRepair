t = int(input())

for i in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    # cnt = 0
    maxi = 0
    p = True
    for j in range(len(a)):
        if len(a) == 1:
            print(max(a[j], n - a[j] + 1))
            p = False
            break
        if j == 0:
            x = a[j]
        elif j == len(a) - 1:
            x = max(n - a[j] + 1, (a[j] - a[j - 1]) // 2 + 1)
        else:
            x = (a[j] - a[j - 1]) // 2 + 1
        maxi = max(maxi, i)
    if p:
        print(maxi)