#author : Piyush Rajendra Chaudhari

k1, p = list(map(int, input().split()))
l = [11, 22, 33, 44, 55, 66, 77, 88, 99]

for i in range(1, 10):
    for j in range(0, 10):
        s = str(i) + str(j) + str(j) + str(i)
        num = int(s)
        l.append(num)

# print(l)

for i in range(1, 10):
    for j in range(0, 10):
        for k in range(0, 10):
            s = str(i) + str(j) + str(k) + str(k) + str(j) + str(i)
            num = int(s)
            l.append(num)

for i in range(1, 10):
    for j in range(0, 10):
        for k in range(0, 10):
            for m in range(0, 10):
                s = str(i) + str(j) + str(k) + str(m) + str(m) + str(k) + str(j) + str(i)
                num = int(s)
                l.append(num)

for i in range(1, 10):
    for j in range(0, 10):
        for k in range(0, 10):
            for m in range(0, 10):
                for n in range(0, 10):
                    s = str(i) + str(j) + str(k) + str(m) + str(n) + str(n) + str(m) + str(k) + str(j) + str(i)
                    num = int(s)
                    l.append(num)

l.append(100000000001)   # 6 digits each with reverse


ans = sum(l[:k1])
print(ans % p)