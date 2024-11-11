x, y = map(int, input().split())
while y>0: x, y = y, x%y
print(y)