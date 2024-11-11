a = int(input())
c = a
b = int(input())
count = 0

while a < b:
    a *= c
    count += 1

if b == a:
    print('YES')
    print(count)
else:
    print('NO')