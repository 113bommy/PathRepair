
n = int(input())

flag = 'No'

for i in range(n//7):
    if (n-(i+1)*7)%4 == 0:
        flag = 'Yes'

print(flag)

