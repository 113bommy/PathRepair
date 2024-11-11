temp = input().split(' ')
n = int(temp[0])
k = int(temp[1])
temp = input().split(' ')
mas = []
sum = 0
for i in range(n):
    mas.append(int(temp[i]))


for i in range(n):
    sum += mas[i]
d = 0

if sum%k:
    print('NO')
    exit(0)
else:
    d = sum/k

rez = []
rez.append(0)
temp = 0
for i in range(n):
    temp += mas[i]

    if (temp == d):
        temp = 0
        rez.append(i+1)

    if (temp > d):
        print('NO')
        exit(0)

print("YES")
for i in range(1, len(rez)):
    print(rez[i] - rez[i-1], end = ' ')