n = int(input())
a = list(map(int, input().split()))
a = sorted(set(a))
if len(a) < 3:
    print('NO')
    exit()
n = len(a)

for i in range(2, n):
    if a[i] < a[i - 1] + a[i - 2]:
        print('YES')
        exit()
print('NO')
