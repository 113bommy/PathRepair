n = int(input())

if n % 2 == 1:
    if n == 1:
        m = 3
    else:
        m = 1
else:
    # For even number, n^2 - 2n + 1
    if n == 2:
        m = 2
    else:
        m = n - 2
print(m)