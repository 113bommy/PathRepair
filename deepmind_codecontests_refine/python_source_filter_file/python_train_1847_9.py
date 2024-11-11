l = []
for k in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    s = sum(a)
    for i in range(n):
        l.append((s-a[i], (k+1, i+1)))
l.sort()

for i in range(len(l)-1):
    if l[i][0] == l[i+1][0] and l[i][1][0] != l[i+1][1][0]:
        print('YES')
        print(l[i][1][0], l[i+1][1][0])
        print(l[i][1][1], l[i+1][1][1])
        exit()
print('NO')