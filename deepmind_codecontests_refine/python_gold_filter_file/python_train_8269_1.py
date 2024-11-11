n = int(input())
a = []

for i in range(n):
    a.append(list(map(int,input().split())))

a.sort()

for i in range(n - 1):
    if a[i][1] > a[i + 1][1]:
        print('Happy Alex')
        exit(0)

if i == n - 2 or 1:
    print('Poor Alex')