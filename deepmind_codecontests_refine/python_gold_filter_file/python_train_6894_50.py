n = int(input())
l = []
for i in range(n):
    a = list(map(int, input().strip().split()))[:2]
    if a[0] % a[1] == 0:
        l.append("YES")
    else:
        l.append("NO")
for j in l:
    print(j)