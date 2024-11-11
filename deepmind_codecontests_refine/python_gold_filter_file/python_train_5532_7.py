s = str(input())
su = 0
for i in s:
    if i=='4' or i=='7':
        su+=1

if su==7 or su==4:
    print('YES')
else:
    print('NO')