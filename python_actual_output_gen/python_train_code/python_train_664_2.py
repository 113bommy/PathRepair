# dice_tower.py
t = int(input())
a = list(map(int,input().split()))
for i in range(t):
    if a[i]%14>=1 and a[i]%14<=7 and a[i]>=15:
        print('YES')
    else:
        print('NO')