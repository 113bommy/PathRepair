#867A
n = int(input())
a = list(input())
cur = a[0] 
count = 0
total = 0
for i in range(1,n):
    if cur == 'S' and a[i] == 'F':
        count+=1
    if not(cur == a[i]):
        total += 1
    cur = a[i]
if count > (total-count):
    print('YES')
else:
    print('NO')