

arr = [int(x) for x in input().split()]

another = [int(x) for x in input().split()]


x1 = arr[0]
y1 = arr[1]

x2 = arr[2]
y2 = arr[3]


x = another[0]
y = another[1]

dict = {}
check = True
while (x1,y1) not in dict:
    dict[(x1,y1)] = 1
    if x1==x2 and y1==y2:
        check = False
        print('YES')
    
    if x1<=x2:
        x1+=x
    else:
        x1-=x
    
    
    if y1<=y2:
        y1+=y
    else:
        y1-=y



if not check:
    print('NO')
    
