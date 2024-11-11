n, k = map(int, input().split())
a = list(map(int, input().split()))

for _ in range(min(k, 20)):
    new_a = [0]*n
    for i in range(n):
        d = a[i]
        new_a[max(i-d, 0)] += 1
        if i+d+1 <= n-1:
            new_a[i+d+1] -= 1
    for i in range(n-1):
        new_a[i+1] += new_a[i]

    a = new_a

print(*a)
