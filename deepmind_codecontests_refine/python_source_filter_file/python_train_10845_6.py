n,r = map(int,input().split())
lst1 = []
lst2 = []
for i in range(n):
    a,b = map(int,input().split())
    if b >= 0:lst1.append((a,b))
    else:lst2.append((a,b))
lst1.sort()
lst2.sort(reverse = True,key = lambda a:a[0]+a[1])
for i in lst1:
    if r < i[0]:
        print('NO')
        exit()
    r += i[1]
for i in lst2:
    if r < i[1]:
        print('NO')
        exit()
    r += i[0]
print('NO' if r < 0 else 'YES')
