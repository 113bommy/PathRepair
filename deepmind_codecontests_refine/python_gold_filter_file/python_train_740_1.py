n = int(input())
numbers = list(map(int, input().split()))
num = [0] * 1001
matrix = [[0 for i in range(n)] for j in range(n)]
numbers_set = set()
for i in numbers:
    numbers_set.add(i)
    num[i] += 1
ones = 0
one = -1
twos = 0
for i in num:
    if i % 2 == 1:
        ones += 1
        one = num.index(i)
    elif i % 4 == 2:
        twos += 1
if n % 2 == 0:
    if ones or twos:
        print("NO")
        exit()
else:
    if ones != 1 or twos >= n:
        print("NO")
        exit()
iterate = sorted(list(numbers_set))
current_num = iterate[0]
current_pos = 0
for i in range(n // 2):
    for j in range(n // 2):
        if num[current_num] < 4:
            while num[current_num] < 4:
                current_pos += 1
                current_num = iterate[current_pos]
        matrix[i][j] = matrix[i][n - j - 1] = matrix[n - i -
                                                     1][j] = matrix[n - i - 1][n - j - 1] = current_num
        num[current_num] -= 4
if n % 2 == 1:
    current_num = iterate[0]
    current_pos = 0
    num[one] -= 1
    matrix[n // 2][n // 2] = one
    for i in range(n // 2):
        if num[current_num] < 2:
            while num[current_num] < 2:
                current_pos += 1
                current_num = iterate[current_pos]
        matrix[i][n // 2] = matrix[n - i - 1][n // 2] = current_num
        num[current_num] -= 2
        if num[current_num] < 2:
            while num[current_num] < 2:
                current_pos += 1
                current_num = iterate[current_pos]
        matrix[n // 2][i] = matrix[n // 2][n - i - 1] = current_num
        num[current_num] -= 2
print("YES")
for i in range(n):
    for j in range(n):
        print(matrix[i][j], end=" ")
    print()
