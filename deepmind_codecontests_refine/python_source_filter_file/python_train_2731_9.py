t = int(input())

targets = [0, 4, 8, 3, 1, 7, 6, 5, 2]

for i in range(t):
    for j in range(9):
        line = list(input())
        number = ord(line[targets[j]])
        line[targets[j]] = chr(((number - ord('1') + 1) % 9) + 1 + ord('1'))
        print(''.join(line))
