import math

x, y = [bin(int(XXX))[2:] for XXX in input().split(' ')]
if x == y:
    print(0)
    quit()

A = (x + '1')[::-1]
B = str(int(x[::-1]))

if A in y:
    left = y.find(A)
    right = left + len(A) - 1
    if left != -1:
        if (not ('0' in y[0:left])) and (not ('0' in y[right+1:])):
            print('YES')
            quit()
A = A[::-1]
if A in y:
    left = y.find(A)
    right = left + len(A) - 1
    if left != -1:
        if (not ('0' in y[0:left])) and (not ('0' in y[right+1:])):
            print('YES')
            quit()

if B in y:
    left = y.find(B)
    right = left + len(B) - 1
    if left != -1:
        if (not ('0' in y[0:left])) and (not ('0' in y[right+1:])):
            print('YES')
            quit()
B = B[::-1]
if B in y:
    left = y.find(B)
    right = left + len(B) - 1
    if left != -1:
        if (not ('0' in y[0:left])) and (not ('0' in y[right+1:])):
            print('YES')
            quit()

print('NO')