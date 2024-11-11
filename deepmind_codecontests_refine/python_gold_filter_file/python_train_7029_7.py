def func(a,b):
    t = 0
    for i in range(6):
        if a[i] != b[i]:
            
            t+=1
    return t
n = int(input())
A = [0] * n
for i in range(n):
    A[i] = input()
per = 10
for i in range(0, n-1):
    for j in range(i+1, n):
        per = min(per, func(A[i], A[j]))
if n == 1:
    print(6)
else:
    
    if per in (5,6):
        print(2)
    elif per in (3,4):
        print(1)
    elif per in (0,1,2):
        print(0)