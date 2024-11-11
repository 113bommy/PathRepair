import sys

t = int(input())

for _ in range(t):
        n, a, b = [int(x) for x in input().split(' ')]
        if (a-b>1) or (b-a>1) or (a+b+2)>n:
                print('-1')
        elif a >= b:
                x, y = 1, n
                for j in range(a):
                        print(x, y, end=' ')
                        y = y-1
                        x = x+1
                if a == b:
                        print(x, end=' ')
                        for j in range(x+1, y+1):
                                print(j, end=' ')
                else:
                        for j in range(y-1, x-1, -1):
                                print(j, end=' ')
                print('')
        else:
                x, y = 1, n
                for j in range(b):
                        print(y, x, end=' ')
                        y = y-1
                        x = x+1
                for j in range(x, y+1):
                        print(j, end=' ')
                print('')