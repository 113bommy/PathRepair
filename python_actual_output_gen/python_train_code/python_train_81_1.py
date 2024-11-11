for _ in range(int(input())):
    a, b, n = map(int, input().split())
    n = int(n % 100)
    array = [a, b]
    for i in range(2, n + 1):
        fibo = array[i - 2] ^ array[i - 1]
        array.append(fibo)
    print(array[n])
