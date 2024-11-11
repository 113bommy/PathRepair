k = int(input())
arr = list(map(int, input().split()))
bil = 25
otv = "YES"

if arr[0] == 100  or arr[0] == 50:
    print('NO')
else:
    mon = {
        25: 0,
        50: 0,
        100: 0,
    }
    for el in arr:
        if el == 100 and mon[50] >= 1 and ((mon[25] >= 1) or (mon[25] >= 3)):
            if mon[25] >= 3 and mon[50] == 0:
                mon[25] -= 3
                mon[100] += 1
            else:
                mon[50] -= 1
                mon[25] -= 1
                mon[100] += 1
        elif el == 50 and mon[25] >= 1:
            mon[25] -= 1
            mon[50] += 1
        elif el == 25:
            mon[25] += 1
        else:
            otv = "NO"
            break
    print(otv)
    
