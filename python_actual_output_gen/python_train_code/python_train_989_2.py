n = int(input())

for i in range(n//7+1):
    res = n - 7 * i
    if res % 4 == 0 :
        x = res // 4
        print('7' * i + '4' * x)
        exit()

print('-1')