from math import ceil

n = input()
ln = ceil(len(n)/2)
f = 0
if n != n[::-1] :
    for i in range(0,ln):
        if n[i] != n[-(i+1)]:
            if f == 0:
                f = 1
            else:
                print('NO')
                f = 0
                break
elif ln%2==1: print('YES')            
else: print('NO')            
if f==1: print('YES')  