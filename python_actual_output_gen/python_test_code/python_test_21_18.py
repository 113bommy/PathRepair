def CreateBoard(n):
    mat = []
    for i in range(n):
        if i % 2 == 0:
            if n % 2 == 0:
                mat.append('C.'*(n//2))
            else:
                mat.append('C.'*(n//2+1))
        else:
            if n % 2 == 0:
                mat.append('.C'*(n//2))
            else:
                mat.append('.C'*(n//2+1))
    return mat
                

n = int(input())

if n % 2 == 0:
    print(n * n//2)
    for row in CreateBoard(n):
        print(row)
else:
    print((n//2 + 1)**2 + (n//2)**2)
    for row in CreateBoard(n):
        print(row)