n = int(input().strip())
A = list(map(int, input().strip().split()))

m = 0
for i in range(n):
    count = 1

    top = A[i]
    k = (i - 1)
    while k > 0 and A[k] <= top:
        count += 1
        top = A[k]
        k -= 1

    top = A[i]
    k = (i + 1)
    while k < n and A[k] <= top:
        count += 1
        top = A[k]
        k += 1

    m = max(m, count)

print(m)