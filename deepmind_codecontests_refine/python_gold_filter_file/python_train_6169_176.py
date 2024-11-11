test_cases = int(input())
for t in range(test_cases):
    size = int(input())
    if size % 4 == 0:
        print('YES')
    else:
        print('NO')
