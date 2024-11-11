f = input().split(' ')
a = [int(x) for x in f]
n = a[0]
s = a[1]
k = 0
s2 = input().split(' ')
a2 = [int(x) for x in s2]

s3 = input().split(' ')
a3 = [int(x) for x in s3]

for i in range(s,n):
    if a2[i] == 1 and a3[i] == 1:
        k = 1
'''''
if a2[0] == 0:
    print('NO')
    raise SystemExit
elif (a2[s-1] == 0 and a[n-1] == 0) or (a2[s-1] == 0 and a[n-1] == 1 and a3[s-1] == 0):
    print('NO')
    raise SystemExit
elif a2[s-1] == 0 and a3[s-1] == 1 and k ==1:
    print('YES')
'''''

if (a2[0] != 0 and a2[s-1] ==0 and k ==1 and a3[s-1] == 1) or (a2[0] != 0 and a2[s-1] ==1):
    print('Yes')
else:
    print('NO')
