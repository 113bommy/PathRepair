s = input()
a = 0
b = 0
c = 0
d = 0
j = 0
A = []
a2 = 0
b2 = 0
for i in s:
    A.append(i)
while j <len(A)-1:
    if A[j] == 'A' and A[j+1] == 'B' and c != 1:
        c = 1
        a = j
        j = j+1

    elif A[j] == 'B' and A[j+1] == 'A' and d !=1:
        d = 1
        b = j
        j = j+1
    elif A[j] == 'A' and A[j+1] == 'B' and c == 1:
        a2 = j
    elif A[j] == 'B' and A[j+1] == 'A' and d == 1:
        b2 = j
    j = j+1
if c == 1 and d == 1:
    print('YES')
elif c == 0 and d == 0 :
    print('NO')
elif c == 1 and d == 0 and a2 != 0:
    x = 0
    while x <a2-1:
        if A[x] == 'B' and A[x+1] == 'A':
            d = 1
            break
        x = x+1
    if c == 1 and d == 1:
        print('YES')
    else:
        print('NO')
elif c == 0  and d ==1 and b2 != 0:
    y = 0
    while j <b2-1:
        if A[y] == 'A' and A[y+1] == 'B':
            c = 1
            break
        y = y + 1
    if c== 1 and d ==1:
        print('YES')
    else:
        print('NO')
else:
    print('NO')
    
    
    
    
    