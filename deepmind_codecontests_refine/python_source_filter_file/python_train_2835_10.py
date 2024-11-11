t = int(input())
for _ in range(t):
    n = int(input())
    t2 = [int(x) for x in input().split()]
    even= False
    if t2[0] % 2 == 0:
        even == True
    if even:
        for elem in t2[1:]:
            if elem % 2 != 0:
                print('NO')
                break
        else: print('YES')
    else:
        for elem in t2[1:]:
            if elem % 2 == 0:
                print('NO')
                break
        else: print('YES')
