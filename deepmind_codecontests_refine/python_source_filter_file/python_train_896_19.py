n,m = [int(i) for i in input().split()]
l = []
for i in range(n):
    a,b = [int(i) for i in input().split()]
    l.append([i for i in range(a,b+1)])
list = []
for i in l:
    line = ''.join(str(j) for j in i)
    list.append(line)

way = ''
for i in list:
    way = way + i + 'a'
k = 1
a = 0
b = 1
while b<= m:    
    route = str(a)+str(b)
    if way.find(route) != -1:
        a += 1
        b += 1
    else:
        k = 0
        break
if k == 0:
    print('NO')
else:
    print('YES')
    
