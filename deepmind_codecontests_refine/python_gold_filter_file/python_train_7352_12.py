n = int(input())

a = list(map(int, input().split()))[:n]

if(a[-1] >= n - 1):
    print(1)
    exit()

alive = 1
claw = a[-1]


for i in range(n - 2, -1, -1):
    if(claw == 0):
        alive = alive + 1
        claw = a[i]
    else:
        claw = max(a[i], claw - 1)

print(alive)