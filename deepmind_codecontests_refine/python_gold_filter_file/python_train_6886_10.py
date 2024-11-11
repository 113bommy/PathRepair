k = int(input().strip())
l = int(input().strip())
i = 0
temp = 1
while temp < l:
    temp = temp * k
    if temp == l:
        print('YES')
        print(i)
        break
    i += 1
if temp > l:
    print('NO')