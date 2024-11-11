def nextEdge():
    global v
    for i in range(1, v + 1):
        for j in range(i + 1, v + 1):
            yield (i, j)

k = int(input())

if k % 2 == 0:
    print("NO")
elif k == 1:
    print("YES", "1 2", "2 1", sep = "\n")
else:
    n = 2 * k + 4
    m = k * (k + 2)
    print("YES")
    print(n, m, sep = " ")
    a = [i for i in range(1, k)] + [i for i in range(k + 4, 2 * k + 3)]
    b = [k + 2] * (k - 1) + [k + 3] * (k - 1)
    a += [k + 2]
    b += [k + 3]

    v = k + 1
    curr = (1, 2)
    count = k - 1
    for i in nextEdge():
        if (count == 0) or (i != curr and count > 0):
            a.append(i[0])
            b.append(i[1])
            a.append(i[0] + k + 3)
            b.append(i[1] + k + 3)
        else:
            curr = (curr[1] + 1, curr[1] + 2)
            count -= 2
    
    for i in range(m):
        print(a[i], b[i], sep = " ")
