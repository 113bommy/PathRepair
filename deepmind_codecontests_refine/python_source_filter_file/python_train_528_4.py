n = int(input())
for q in range(n):
    x, y, k = map(int, input().split())
    if max(x, y) > k:
        print(-1)
    else:
        if 0 == (x + y) % 2:
            if k % 2 == (x + y) % 2:
                print(k)
            else:
                print(k - 2)
        else:
            print(k - 1)
