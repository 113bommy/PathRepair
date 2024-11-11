n = int(input())
new_n = n
if n % 2 == 0:
    print(n // 2)
else:
    i = 3
    count = 0
    while i*i <= n:
        if n % i == 0:
            new_n = n - i
            break
        i += 1
    if new_n == 0 or new_n == n:
        print(1)
    else:
        print((new_n//2) + 1)
