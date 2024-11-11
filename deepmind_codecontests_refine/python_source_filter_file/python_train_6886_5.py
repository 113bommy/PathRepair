a = int(input())
b = int(input())
count = 0

while a < b:
    a *= a
    count += 1

if b == a:
    print('YES')
    print(count)
else:
    print('NO')