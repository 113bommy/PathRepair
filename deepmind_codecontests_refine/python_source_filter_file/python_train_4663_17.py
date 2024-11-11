n = int(input())

k = 2
count = 1
while k * k <= n:
    m = n
    while m % k == 0:
        m = m / k
    if m % k == 1:
        count += 1
    k += 1

l = 1
while l * l < n:
    if (n - 1) % l == 0:
        count += 1
    l += 1

if n == 2:
    print(1)
else:
    print(count)