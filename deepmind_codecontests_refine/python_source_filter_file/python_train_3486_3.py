a, b = map(int, input().split())
cases = a
face = set("face")
matrix = []
while cases:
    cases -= 1
    s = list(input())
    matrix.append(s)
check = set()
ans = 0
for row in range(len(matrix)):
    for col in range(len(matrix[0])):
        if matrix[row][col] in face:
            if row < len(matrix)-1 and col < len(matrix[0])-1:
                check.add(matrix[row][col])
                check.add(matrix[row][col+1])
                check.add(matrix[row+1][col])
                check.add(matrix[row+1][col+1])
                if check == face:
                    ans += 1
                    check = set()

print(ans)
