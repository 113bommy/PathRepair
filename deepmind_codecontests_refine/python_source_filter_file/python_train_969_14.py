n =int(input())
k = list(map(int, input().split()))

z = list()
c =list()


for i in range(1, len(k)):

    c.append(k[i -1])
    e = max(c)
    d = min(c)

    if k[i - 1] <k [i] and k[i] >e or k[i] <d:
        if k[i] not in z:
            z.append(k[i])

if n ==1:
    print(0)
else:
    print(z)

    print(len(z))
