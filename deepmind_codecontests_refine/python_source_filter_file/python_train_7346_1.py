n = int(input())

for i in range(1, n):
    candies = (i * (i + 1)) / 2

    if candies > n:
        print(i - 1)
        last = n - (((i - 1) * i) // 2)
        spread = []
        for j in range(1, i):
            if j == i - 1:
                spread.append(j + last)
            else:
                spread.append(j)
        print(*spread)
        break

    elif candies == n:
        print(i)
        print(*range(1, i + 1))
        break

