n = int(input())
prints = list(input())

for i in range(n - 1):
    x, y = prints[i], prints[i + 1]

    if x == '.' and y != '.':
        first_letter = i + 1
    if x != '.' and y == '.':
        last_letter = i
    if x == 'R' and y == 'L':
        print(i + 1, i + 2)
        exit()

if prints[first_letter] == 'R':
    print(first_letter + 1, last_letter + 2)
    exit()

print(last_letter + 1, last_letter)
