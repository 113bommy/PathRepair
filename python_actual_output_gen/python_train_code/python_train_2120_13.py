n = int(input())
x,y = [*map(int,input().split())]
if (x-1 + y-1) <= (n-x + y-x):
    print('White')
else:
    print('Black')