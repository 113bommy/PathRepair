n = int(input())

for i in range(n//4+1):
    res = n - 4 * i
    if res % 7 == 0 :
        x = res // 7
        print('4' * i + '7' * x)
        exit()

print('-1')