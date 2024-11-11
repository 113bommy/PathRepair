line = input().split(' ')
n = int(line[0])
x = int(line[1])

count = 0
line = input().split(' ')
for i in range(n):
    count += int(line[i])

if count + n - 1 == x:
    print("YES")
else:
    print("NO")
