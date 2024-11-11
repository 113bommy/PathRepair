t = input()
t = int(t)

for i in range(t):
    n = input()

    first = list(map(int, input().split(' ')))
    found = False

    for j in range(0, len(first) - 1):
        if abs(first[j] - first[j+1]) > 1:
            print('YES')
            print(j, j+1)
            found = True
            break

    if not found:
        print('NO')