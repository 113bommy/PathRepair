t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    if n > k:
        print(abs(n-k))
    elif n%2 == k%2:
        print(0)
    else:
        print(1)