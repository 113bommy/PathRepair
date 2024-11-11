t = int(input())
for i in range(t):
    k = int(input())
    a = input()
    b = input()
    ans = 0
    h = 3
    v = 0
    for j in range(k):
        if a[j] == "0":
            if b[j] == "0":
                if h == 1:
                    h = 3
                    v = 0
                    ans += 2
                else:
                    h = 0
                    v += 1
            else:
                if h != 0:
                    ans += 2
                    h = 3
                    v = 0
                else:
                    ans += 1 + v
                    h = 3
                    v = 0
        else:
            if b[j] == "0":
                if h != 0:
                    ans += 2
                    h = 3
                    v = 0
                else:
                    ans += 1 + v
                    h = 3
                    v = 0
            else:
                if h == 0:
                    ans += 1 + v
                    h = 3
                    v = 0
                else:
                    h = 1
    if h != 3:
        print(ans + ((h + 1) % 2 * v))
    else:
        print(ans)