n = int(input())
x , y = map(int, input().split())
w = max(x-1,y-1)
b = max(n-x , n-y)
if w<=b:
    print("White")
else:
    print('Black')