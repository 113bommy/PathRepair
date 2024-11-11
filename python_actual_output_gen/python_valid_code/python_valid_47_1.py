x, y = input().split()

if x == y:
    print(x+'0', y+'1')
elif int(x)+1 == int(y):
    print(x+'9', y+'0')
elif (x,y) == (9,1):
    print(9, 10)
else:
    print(-1)