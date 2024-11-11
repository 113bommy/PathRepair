n = int(input())
print(min([sum(map(int, str(i) + str(n - i))) for i in range(1, n // 2 + 1)]))
