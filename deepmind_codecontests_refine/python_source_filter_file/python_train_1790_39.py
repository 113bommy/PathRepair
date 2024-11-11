n = int(input())
z = n
b = '0'
a = []
Q = 0
while n > 0:
    x = int(input())
    if x > 4 and x % 2 == 0:
        a += ['0']
    elif x < 3:
        a += ['2']
    else:
        a += ['1']
    n = n-1
while Q != z:    
    try:
        print(a[Q])
    except Exception as exc:
        print(str(exc))
    Q = Q + 1
    