r, c = [int(i) for i in input().split()]
if r == 1 and c == 1:
    print(0)
else:
    if c == 1:
        for i in range(1,r+1):
            print(i)
    else:
        for i in range(1,r+1):
            print(*[i*(r+j) for j in range(1,c+1)])