m = int(input())
num = [int(n) for n in input().split()]
sum = 0
for i in range(0,m):
    sum += num[i]
if sum % m:
    print('0')
else:
    ave = sum // m
    cnt = 0
    for i in range(0,m):
        if num[i] == ave:
            cnt += 1
    print(cnt)
    for i in range(0,m):
        if num[i] == ave:
            print(num[i],end=' ')