a, b = map(int, input().split())
if b == 0 and a>1:
    print('No solution')
else:
    print(str(b) + (a-1) * '0')