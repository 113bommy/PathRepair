n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

ab = [[a[i], b[i]] for i in range(n)]
ab.sort(key=lambda x:x[1])

a = [ab[i][0] for i in range(n)]
b = [ab[i][1] for i in range(n)]

a2 = [[a[i], i] for i in range(n)]
a2.sort(key=lambda x:x[0])

flag1 = 0
for i in range(n):
    if a2[i][0] > b[i]:
        flag1 = 1

flag2 = 1
idx = a2[0][1]
cnt = 0
while idx != 0:
    idx = a2[idx][1]
    cnt += 1

if cnt == n-1:
    for i in range(n-1):
        if a2[i+1] <= b[i]:
            flag2=0
            break
else:
    flag2 = 0

if flag1 == 1 or flag2 == 1:
    print('No')
else:
    print('Yes')