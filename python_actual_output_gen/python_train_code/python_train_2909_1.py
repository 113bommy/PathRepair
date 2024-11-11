n, m = list(map(int, input().split()))

lst = [list(input()) for i in range(n)]

a = []
b = []

for i in range(n):
    flag = True
    for j in lst[i]:
        if j == '*':
            flag = False
    if not flag:
        a.append(i)
        
for x in range(m):
    flag = True
    for i in lst:
        if i[x] == '*':
            flag = False
    if not flag:
        b.append(x)

# print(a, b)

tmp = a[-1] + 1
lst = lst[a[0]:tmp]

tmp = b[-1] + 1
for i in range(len(lst)):
    lst[i] = lst[i][b[0]:tmp]
    
for i in lst:
    print(' '.join(i))