x = int(input())
y = int(input())
if (y - x) % 2 == 0:
    print((y - x) // 2, (x + y) // 2, sep=' ', end='\n')
else:
    print(-1)
