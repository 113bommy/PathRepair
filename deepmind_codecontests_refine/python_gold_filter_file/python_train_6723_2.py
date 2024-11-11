x = int(input())
y = int(input())
if (x - y) % 2 == 0:
    print((x - y) // 2, (x + y) // 2, sep=' ', end='\n')
else:
    print(-1)
