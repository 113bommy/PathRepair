def eq(n, m):
    count = 0
    for i in range(int(n ** 0.5) + 1):
        for j in range(n + 1):
            if i ** 2 + j > n:
                break
            elif i ** 2 + j == n:
                if j ** 2 + i == m:
                    count += 1
    return count

n, m = (int(i) for i in input().split())
print(eq(n, m))