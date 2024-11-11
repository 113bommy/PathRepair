a = list(map(int,input().split(" ")))

n = a[0]
m = a[1]
x = a[2]
y = a[3]
# this is x_start,y_start)
print(x,y)
move = 1
x_start = x
y_start = y


for i in range(n):
    if i == 0:
        x = n
        print(x,y)
        move += 1
        continue
    
    x -= 1
    if x == x_start:
        continue
    else:
        print(x,y)
        move += 1


y = 1
# this is (1,1)
print(x,y)
move += 1


odd = True

while True:
    if odd is True:
        x+=1
    elif odd is False:
        x-=1
    
    
    if x > n:
        x = n
        y+=1
        if y == y_start:
            y += 1
        odd = False
    elif x<1:
        x = 1
        y+=1
        if y == y_start:
            y += 1
        odd = True
            
    print(x,y)
    move+=1
    if move == m*n:
        break