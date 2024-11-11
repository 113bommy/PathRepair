n = int(input())
x,y = map(int, input().split())
w = max(x,y)-1
b = min(n-x,n-y)
if w > b:
    print("Black")
else:
    print("White")