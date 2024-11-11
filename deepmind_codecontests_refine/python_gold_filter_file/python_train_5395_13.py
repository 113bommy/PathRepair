print(sum([sum([i % j == 0 for j in range(2, i)]) == 6 for i in range(105, int(input()) + 1, 2)]))
