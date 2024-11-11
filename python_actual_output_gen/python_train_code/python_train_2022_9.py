a = int(input())
for i in range(2, a // 2):
    if a % i == 0:
        print('{f1}{f2}'.format(f1 = i, f2 = a // i))
        break