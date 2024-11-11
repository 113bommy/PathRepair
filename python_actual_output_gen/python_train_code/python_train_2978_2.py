
num_tests = int(input())

for i in range(num_tests):
    n = int(input())
    digits = input()
    for i, d in enumerate(digits):
        if d == '8' and i + 9 < n:
            print('YES')
            break
        if i + 10 > n:
            print('NO')
            break
