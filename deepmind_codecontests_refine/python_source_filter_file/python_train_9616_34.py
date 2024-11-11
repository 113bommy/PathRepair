int(input())
sp = [int(x) for x in input().split()]
L = sp[0] % 2
L1 = sp[1] % 2
if L == L1:
    for i in range(2, len(sp)):
        if sp[i] % 2 != 0:
            print(i + 1)
            break
else:
    if sp[2] % 2 == L:
        print(2)
    elif sp[2] % 2 == L1:
        print(1)
