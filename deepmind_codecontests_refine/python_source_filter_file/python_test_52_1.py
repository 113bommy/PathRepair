m = 1000000007
for _ in range(int(input())):
    n, k = map(int, input().split())
    b = bin(k)[2:][::-1]
    count = 0
    a = 0
    for i in b:
        if i == "1":
            count = (count + pow(n, a, m)) % m
        m += 1
    print(count)