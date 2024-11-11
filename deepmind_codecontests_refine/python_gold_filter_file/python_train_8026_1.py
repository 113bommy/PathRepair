n=int(input())
mx = 0
for i in range(n):
    x, y = map(int, input().split())
    if x+y>mx:
        mx = x+y
        xi = x
        yi = y
print(xi+yi)