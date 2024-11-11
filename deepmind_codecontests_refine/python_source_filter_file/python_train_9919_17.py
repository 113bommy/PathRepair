kl = int(input())
for i in range(kl):
    n, k = map(int, input().split())
    if n <= 2:
        print(1)
    else:
        print((n+k-3) // k)
