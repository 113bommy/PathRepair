n = int(input())

soft = 0
hard = 0

for i in range(n):
    _, t = input().split()
    if t == 'soft':
        soft += 1
    else:
        hard += 1

for i in range(1, 100):
    # field1 = [[0] * i for j in range(i)]
    # field2 = [[0] * i for j in range(i)]

    s1 = soft
    h1 = hard

    s2 = soft
    h2 = hard

    for j in range(i):
        for k in range(i):
            if (j + k) % 2 == 0:
                s1 -= 1
                h2 -= 1
            else:
                s2 -= 1
                h1 -= 1

    if s1 <= 0 and h1 <= 0 or s2 <= 0 and h2 <= 0:
        print(i)
        break

