n = int(input())
a = list(map(int, list(input())))

for i in range(len(a)):
    sum = 0
    for j in range(i, -1,-1):
        sum += a[j]
    sum1 = 0
    f = 0
    for j in range(i + 1,len(a)):
        sum1 += a[j]
        if sum1 > sum:
            break
        if j == len(a)-1 and sum1 == sum:
            print('YES')
            exit()
        if sum1 == sum and (i+1 == len(a) or a[i+1] != 0):
            sum1 = 0
            continue
        if sum1 > sum:
            break
print('NO')