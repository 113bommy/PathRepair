for _ in range(int(input())):
    n = int(input())
    s = input()
    i, k = 0, 0
    while i < n and s[i] == "0":
        i += 1
    while n - 1 - k >= 0 and s[n - 1 - k] == "1":
        k += 1
    print("0" * i + ("0" if i * k < n else "") + k * "1")
