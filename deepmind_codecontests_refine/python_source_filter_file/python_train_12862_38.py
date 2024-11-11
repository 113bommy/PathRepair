n = int(input())
a = [input() for i in range(n)]
a1 = []
set = 0
for i in range(len(a)):
    if 'OO' in a[i]:
        a[i] = a[i].replace('OO','++')
        break
for i in a:
    if '++'  in i:
        set +=1
if set == 1:
    print('YES')
    for i in a:
        print(i, sep = '\n')

else:
    print('NO')
    
