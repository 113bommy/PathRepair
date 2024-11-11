n = int(input())
small = 3
large = 7

for i in range(n):
    c = int(input())
    if c % small == 0 or c % large == 0:
        print('YES')
    else:
        need = False
        for j in range(34):
            x = c - small * j
            if x > 0 and x % large == 0:
                print('YES')
                need = True
                break
        if need:
            print('NO')