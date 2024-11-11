n = int(input())
print(min([sum(map(int, str(i) + str(n - i))) for i in range((n + 1) // 2)]))
