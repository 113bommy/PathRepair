n = int(input())

for _ in range(n):
    a = int(input())
    s = 3
    ex = 1
    while (a % s !=0):
        ex += 1
        s += pow(2, ex)
    print(a//3)
