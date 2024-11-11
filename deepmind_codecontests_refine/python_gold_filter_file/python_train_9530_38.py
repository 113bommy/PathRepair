from sys import exit

n = int(input())

for _ in range(n):
    s, a, b = input().split()
    a = int(a)
    b = int(b)
    if a >= 2400 and a < b:
        print('YES')
        exit(0)
        
print('NO')
