k = int(input())
n = input()
s = sum(list(map(int, n)))
if s >= k:
    print(0)
else:
    d = [0] * 9
    for i in range(1, 9):
        d[i] = n.count(str(i))
    c = 0
    dif = k - s
    for i in range(1, 10):
        if dif > d[i] * (9-i):
            dif -= d[i] * (9-i)
            c += i
        else:
            cur = dif // (9-i)
            if dif % (9-i) != 0:
                cur += 1
            c += cur
            break
    print(c)

