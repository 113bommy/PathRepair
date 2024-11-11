x,y = map(int,input().split())
if(y == 0 or ( x == 0 and y>1)):
    print('No')
    exit()
if(y - x == 1):
    print("Yes")
elif(x - y < -1):
    print("No")
elif((x-y-1)%2 == 0 and x - y > 1):
    print("Yes")
else:
    print("No")