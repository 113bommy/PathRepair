n = int(input())
i = 0
j = 0
for i in range(n):
    x, y = input().split()
    x = int(x)
    y = int(y)
    if(x, y) > (0, 0):
        i = i + 1
    elif(x, y) < (0, 0):
        j = j + 1
if( i == n):
    print("Yes")
elif( j == n):
    print("Yes")
elif( i == 1):
    print("Yes")
elif(j == 1):
    print("Yes")
else:
    print("No")
