t = int(input())
for _ in range(t):
    n, k =map(int, input().split())
    if n >= k:
        if n%2 == k%2 == 0:
            print(0)
        else:
            print(1)
    else:
        print(k-n)
