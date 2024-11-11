for _ in range(int(input())):
    n = int(input())
    s = input()
    l, r = -1, -1
    if n <= 1:
        print(l, r)
    else:
        for i in range(n - 1):
            if s[i] == "a" and s[i + 1] == "b" or s[i] == "b" and s[i + 1] == "a":
                l, r = i, i + 1
                break
        print(l, r)
