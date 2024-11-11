n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
d1 = [0] * 6
d2 = [0] * 6
for i in range(n):
    d1[a[i]] += 1
    d2[b[i]] += 1

diff1 = 0
diff2 = 0
for i in range(6):
    if (d1[i] + d2[i] % 2) != 0:
        print(-1)
        exit()
    if d1[i] - d2[i] > 0:
        diff1 += abs(d1[i] - d2[i])
    else:
        diff2 += abs(d1[i] - d2[i])

if diff1 == diff2 and diff1 % 2 == 0:
    print(diff1 // 2)
else:
    print(-1)
