a = list(map(int, input().split()))

from math import sqrt

t = a[0] * a[1] + a[2] * a[3] + a[4] * a[5]
c = ('A', 'B', 'C')
p = int(sqrt(t))
if p ** 2 != t:
    print('-1')
    exit()

k = 0
for i in a:
    if i == p:
        k += 1

if k == 0 or k == 2:
    print('-1')
    exit()

b = list()
ans = ''
if (k == 3):
    for i in a:
        if i != p:
            b.append(i)
    if sum(b) != p:
        print('-1')
        exit()
    for i in range(p):
        for j in range(3):
            ans += (c[j] * b[j])
        ans += '\n'
    print(p)
    print(ans)
    exit()

arr = []
arr.append([a[0], a[1]])
arr.append([a[2], a[3]])
arr.append([a[4], a[5]])
arr[0].sort(reverse=True)
arr[1].sort(reverse=True)
arr[2].sort(reverse=True)
arr[0] += [0]
arr[1] += [1]
arr[2] += [2]
arr.sort()
arr[0][0], arr[0][1] = arr[0][1], arr[0][0]
arr[1][0], arr[1][1] = arr[1][1], arr[1][0]
arr[2][0], arr[2][1] = arr[2][1], arr[2][0]


kol = p - arr[2][0]
for i in range(2):
    for j in range(2):
        if arr[0][i] == arr[1][j] == kol and arr[0][1 - i] + arr[1][1 - j] == p:
            ans = (((c[arr[2][2]] + '') * p).__str__() + '\n') * arr[2][0]
            ans += (((c[arr[0][2]] + '') * arr[0][1 - i]) + ((c[arr[1][2]] + '') * arr[1][1 - j]) + '\n') * kol
            print(p)
            print(ans)
            exit()
print('-1')