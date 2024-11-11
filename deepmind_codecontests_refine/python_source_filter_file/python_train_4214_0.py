n = int(input())
a = []
for i in range(n):
    a.append(int(input()))    

a.sort()    
res = None
if n == 0:
    res = [1, 1, 3, 3]
elif n == 1:
    res = [a[0], 3*a[0], 3*a[0]]
elif n == 2 and a[1] <= 3*a[0]:
    res = [a[0]*4 - a[1], a[0]*3]
elif n == 3:
    for v in range(1501):
        s = a + [v]
        s.sort()
        if s[0]*3 >= s[2] and s[1] + s[2] == 4*s[0]:
            res = [v]
            break
elif n == 4 and a[0]*3 == a[3] and a[1] + a[2] == 4*a[0]:
    res = []

if res == None:
    print('NO')
else:
    print('YES')
    for b in res:
        print(b)

