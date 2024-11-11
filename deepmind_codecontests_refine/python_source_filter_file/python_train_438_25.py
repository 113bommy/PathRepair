from collections import defaultdict

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))

    rooms = set()
    good = True
    for k in range(2*n):
        value = k + a[k % n]
        if value in rooms:
            good = False
            break
        rooms.add(value)
    
    if good:
        print('YES')
    else:
        print('NO')