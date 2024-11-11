n = int(input())
if n == 1:
    print(1)
    print(1,1)
else:
    x = (n) // 2 + 1
    print(x)
    i = 1
    j = 1
    for k in range(n):
        print(i, j)
        i += (k % 2 == 0)
        j += (k % 2)