t = int(input())
for i in range(t):
    A, B = tuple([int(x) for x in input().split(" ")])
    b = 0
    n = 0
    for j in range(1,len(str(B))):
        b = b*10 + 9
        if b < B:
            n += 1
    print(A*n)


