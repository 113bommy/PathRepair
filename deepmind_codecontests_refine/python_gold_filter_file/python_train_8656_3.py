
num_tests = int(input())

for i in range(num_tests):
    n = int(input())
    digits = input()
    for i, d in enumerate(digits):
        if d == '8' and i + 10 < n:
            print('YES')
            break
        elif i + 11 > n:
            print('NO')
            break
