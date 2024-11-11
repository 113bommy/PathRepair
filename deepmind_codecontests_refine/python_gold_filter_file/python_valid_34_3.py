q = int(input())
for _ in range(q):
    n = [int(x) for x in input().split()]
    k = n[1]
    n = n[0]
    a = [int(x) for x in input().split()]
    m = 2 - k*(a[0]|a[1])
    for i in range(max(n-200,0), n):
        for j in range(i+1, n):
            x = ((i + 1) * (j + 1) - k * (a[i] | a[j]))
            if m < x:
                m = x
    print(m)