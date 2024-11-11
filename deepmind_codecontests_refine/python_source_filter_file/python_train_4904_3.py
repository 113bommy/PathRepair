n = int(input())
if n > 2:
    s = n * (n - 1) // 2
    i = 2
    while s % i != 0:
        i += 1
    print("Yes")
    print(1, i)
    print(n - 1, end = ' ')
    for j in range(1, n):
        if i != j:
            print(j, end = ' ')
else:
    print("No")
