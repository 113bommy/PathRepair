n = int(input())
arr = [int(i) for i in input().split()]

if n % 2 == 1:
    print("YES")
    print(n - 2)
    for i in range(n // 2):
        print(str(2 * i + 1), str(2 * i + 2), str(2 * i + 3))
    for i in range(n // 2 - 1):
        print(str(2 * i + 1), str(2 * i + 2), str(n - 1))
else:
    xor = arr[0]
    for i in range(1, n):
        xor = xor ^ arr[i]

    if xor == 0:
        print("YES")
        print(n - 3)
        for i in range(n // 2 - 1):
            print(str(2 * i + 1), str(2 * i + 2), str(2 * i + 3))
        for i in range(n // 2 - 1):
            print(str(2 * i + 1), str(2 * i + 2), str(n - 1))

    else:
        print("NO")
