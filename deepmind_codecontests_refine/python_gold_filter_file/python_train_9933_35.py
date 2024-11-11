n, k = [int(i) for i in input().split(" ")]
A = [int(i) for i in input().split(" ")]
if len(A) <= k:
    print(1)
else:

    cons = [0]
    for i in range(len(A)):
        cons.append(cons[-1] + A[i])

    a = []
    Min = 10 ** 9
    ans = 0
    i = 0
    j = k
    while j <= n:
        a.append(cons[j] - cons[i])
        if cons[j] - cons[i] < Min:
            Min = cons[j] - cons[i]
            ans = i
        j += 1
        i += 1
    print(ans + 1)