n = int(input())
x,y = map(int, input().split())
w = max(x,y)-1
b = n-min(x,y)
if w > b:
    print("Black")
else:
    print("White")