t = int(input())
for _ in range(t):
    n, k = map(int, input().split(' '))
    if n <= k:
        print(k-n)
    else:
        if n%2 == 0:
            print(0)
        else:
            print(1)
