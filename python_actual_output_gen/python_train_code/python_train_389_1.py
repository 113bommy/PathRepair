n = int(input())
a = []
total=0
count=0
for _ in range(n):
    a.append(list(map(int, input().rstrip().split())))
for i in range(n):
    for j in range(n):
        total+=a[i][j]
    if total==0:
        count+=1
if count==n:
    print('YES')
else:
    print('NO')