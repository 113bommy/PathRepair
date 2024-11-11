n = int(input())
if n == 1:
    print("NO")
elif n == 2:
    print("NO")
else:
    sum_of_n = (n * (n + 1)) // 2
    partition = 0
    for i in range(2, sum_of_n):
        if sum_of_n % i == 0:
            partition = i
            break
    if partition == 0:
        print("NO")
    else:
        print("YES")
        print(1, partition)
        print(n - 1, end=' ')
        for i in range(1, n + 1):
            if partition == i:
                continue
            else:
                print(i, end=' ')
