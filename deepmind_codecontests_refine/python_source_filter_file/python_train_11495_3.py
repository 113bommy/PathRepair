n = int(input())
#k, m = map(int, input().split()) 
#s = input()
c = list(map(int, input().split()))
a = [0] * 2
for i in range(n):
    if c[i] == 100:
        if a[1] > 0 and a[0] > 0:
            a[0] -= 1
            a[0] -= 1
        elif a[0] > 2:
            a[0] -= 3
        else:
            print('NO')
            break
    elif c[i] == 50:
        if a[0] > 0:
            a[0] -= 1
            a[1] += 1
        else:
            print('NO')
            break
    else:
        a[0] += 1
else:
    print('YES')