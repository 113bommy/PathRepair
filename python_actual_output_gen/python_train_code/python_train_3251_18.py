n = int(input())
a = list(map(int, input().split()))

a.sort()

for i in range(0, n - 3):
    if a[i] + a[i+1] > a[i+2]:
        print('YES')
        exit()

print('NO')