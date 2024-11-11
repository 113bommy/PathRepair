n=int(input())
i=input()
a, b=list(i[:n]), list(i[n:])
a.sort
b.sort()
q = p = 1
for i in range(n):
    if a[i] > b[i]:
        p = 0
    elif a[i] < b[i]:
        q = 0
    else:
        p = q = 0
if (p+q>0):
    print('YES')
else:
    print('NO')
        
