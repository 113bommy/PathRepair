n = int(input())

for _ in range(n):
    k = int(input())
    if k in [1, 2, 4]:
        print(-1)
    elif (k % 3) == 2:
        print((k-5)//3, 1, 0)
    elif (k % 3) == 1:
        print((k-7)//3, 0, 1)
    else:
        print(k//3, 0, 0)
        
