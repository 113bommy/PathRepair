n = int(input())
x, y =  map(int, input().split())
print('Blak' if n - min(x,y)< max(x, y) - 1 else 'White')