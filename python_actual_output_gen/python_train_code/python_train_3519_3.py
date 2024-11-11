t = int(input())
def swap(x, y):
    return y, x
for _ in range(t):
    s = input()
    mx = 0
    for i in range(10):
        for j in range(10):
            cur = 0
            x, y = i, j
            for a in s:
                if int(a) == x:
                    cur += 1
                    # print(x, y, swap(x, y))
                    x, y = swap(x, y)
            if len(s) % 2 == 1 and i != j:
                cur -= 1
            mx = max(mx, cur) 

    print(len(s) - mx)