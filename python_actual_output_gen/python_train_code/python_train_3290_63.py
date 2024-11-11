
n = int(input())
for i in range(n):
    name, a, b = input().split()
    
    if int(a) > int(b) > 2399:
        print('YES')
        exit()

print('NO')
