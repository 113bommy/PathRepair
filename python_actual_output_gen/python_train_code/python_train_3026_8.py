n = int(input())
t1, t2 = 1, n ** 2
for i in range(0, n):
    for j in range(0, n):
        print(t1, t2, sep = ' ', end = '')
        t1 += 1
        t2 -= 1
    print('\n')