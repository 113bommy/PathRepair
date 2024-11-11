n = int(input())
a = list(map(int,input().split()))
count = 0
for i in range(len(a)):
    if a[i] == 0:
        count += 1
if n == 1:
    if [0] == 1:
       print('YES')
    else:
        print('NO')
elif count > 1 or count == 0:
    print('NO')
else:
    print('YES')