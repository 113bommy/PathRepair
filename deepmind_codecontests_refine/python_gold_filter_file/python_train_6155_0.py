n = int(input())
x, y =  map(int, input().split())
print('Black' if n - min(x,y)< max(x, y) - 1 else 'White')