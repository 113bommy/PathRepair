x1 , y1 = map(int,input().split())
x2 , y2 = map(int,input().split())

n = max(abs(x1-y1),abs(y1-y2))

print(n)
