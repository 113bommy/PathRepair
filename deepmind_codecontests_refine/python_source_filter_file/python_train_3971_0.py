a = list(input())
b = list(input())
x = ['a','e','i','o','u']
m = len(a)
n = len(b)
c = 0
if  m>n:
    print('No')
else:
    for i in range(m):
        if a[i]in x and b[i] in x:
            c+=1
        elif a[i] not in x and b[i] not in x:
            c+=1
    if c == m:
        print('YES')
    else:
        print('NO')