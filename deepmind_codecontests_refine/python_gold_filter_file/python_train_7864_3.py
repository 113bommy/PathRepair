n = int(input())
days = list(map(int,input().split()))

a = days[0]
up = False
down = False

if n > 1 and days[n - 2] > days[n - 1]:
    down = True
    up = False
elif n > 1:
    up = True
    down = False

if days[n - 1] is 15:
    down = True
    up = False
elif days[n - 1] is 0:
    up = True
    down = False

if up is True:
    print("UP")
elif down is True:
    print("DOWN")
else:
    print("-1")