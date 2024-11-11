t = int(input())

for br in range(t):
    n, k = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    max_ind = 0
    max_k = 0
    p_k = 0
    prev = [0] * n

    for j in range(1, n - 1):
        bool1 = (a[j] > a[j - 1]) and (a[j] > a[j + 1])
        if bool1:
            p_k += 1
        prev[j] = p_k

    prev[n - 1] = p_k

    for i in range(n - k + 2):
        prev_k = prev[i + k - 2] - prev[i]
        if prev_k > max_k:
            max_k = prev_k
            max_ind = i

    print(max_k + 1, max_ind+1)