n = int(input())
a = list(map(int, input().split()))
z, summ, cnt = 0, 1, 0

for i in range(len(a)):
    if a[i] == 0: z += 1
    elif a[i] not in {-1, 1, 0}: cnt = cnt + abs(a[i]) - 1
    if a[i] < 0: a[i] = -1
    else: a[i] = 1
    summ *= a[i]

if (summ == 1) or (summ == -1 and z != 0): print(cnt + z)
else: print(cnt + 2)