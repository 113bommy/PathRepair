n = int(input())
if n < 3:
    print(n)
    print(n)
elif n == 3:
    print(2)
    print(1, 3)
else:
    print(n)
    arr = list(range(1, n + 1))
    arr = arr[::2][::-1] + arr[1::2][::-1]
    print(*arr)
