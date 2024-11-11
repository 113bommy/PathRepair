t = int(input())
while t:
    n = int(input())
    s = input()
    if "0" not in s:
        print(1, n // 2, n - n // 2, n)
    else:
        for i in range(n):
            if s[i] == "0":
                if i >= n // 2:
                    print(1, i+1, 1, i)
                else:
                    print(i+1, n, i+2, n)
                break
    t -= 1

