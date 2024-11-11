n = int(input())
l = [0 for i in range(n)]
for _ in range(n-1):
    a, b = list(map(int, input().split()))
    l[a-1] += 1
    l[b-1] += 1
for i in range(n):
    if (l[i] == 2):
        print('NO')
        break
else:
    print('YES')