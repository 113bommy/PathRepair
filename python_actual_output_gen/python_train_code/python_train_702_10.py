for _ in range(int(input())):
    n, k = list(map(int, input().split()))
    if k >= n:
        print(k - n)
    else:
        if n % 2 == 0 and k % 2 == 0 or n % 2 != 0 or k % 2 != 0:
            print(0)
        else:
            print(1)