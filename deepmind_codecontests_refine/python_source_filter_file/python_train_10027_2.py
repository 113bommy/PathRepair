from math import ceil

def slv(a,b):
    if a % b == 0:
        print('NO')
        return
    print('YES')
    print(a, a*(2*b-1), 2*a*b)



t = int(input())

for _ in range(t):
    a,b = map(int, input().split())
    slv(a,b)
