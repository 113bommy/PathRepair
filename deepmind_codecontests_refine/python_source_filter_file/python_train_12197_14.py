n = int(input())

if n < 25:
    print(-1)
else:
    r = False
    for i in range(5, int(n ** 0.5) + 1):
        if n % i == 0:
            r = True
            break
    if r:
        if n == 25:
            a = "aeioueiouaiouaeouaeiuaeio"
            print(a * (n // 25) + a[:n % 25])
        else:
            a = "aeiou"
            print(a * (n // 5) + a[:n % 5])
    else:
        print(-1)
