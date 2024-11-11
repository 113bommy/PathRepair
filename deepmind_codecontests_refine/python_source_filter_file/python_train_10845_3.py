
n,r = map(int,input().split())

la1 = []
la2 = []
for i in range(n):
    a,b = map(int,input().split())
    if b>=0:
        la1.append([a,b])
    else:
        la2.append([a+b,a,b])

la1.sort()
la2.sort(reverse=True)
for i in range(len(la1)):
    if r>=la1[i][0]:
        r+=la1[i][1]
    else:
        print('NO')
        exit()

for i in range(len(la2)):
    if r>=la2[i][1]:
        r+=la2[i][2]
    else:
       print('NO')
       exit()


if r>0:
    print('YES')
else:
    print('NO')






