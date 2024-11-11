n, p, q = map(int, input().split())
s = input()
for i in range(n // p + 1):
    if (n - i * p) % q == 0:
        print(i + (n - i * p) // q)
        for j in range(i):
            print(s[j * p:j * p + p])
        for j in range((n - i * p) // q):
            print(s[i * p + j * q: i * p + j * q + q])
        exit()
print(-1)