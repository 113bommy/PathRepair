n , m , x , y = map(int , input().split())
for i in range(y,m+1):
    print(x,  i)
for i in range(y-1 , 0 , -1):
    print(x , i)

c = 0

for i in range(x-1, 0 , -1):
    if c%2 == 0:
        for j in range(1 , m+1):
            print(i , j)
    else:
        for j in range(m , 0 , -1):
            print(i,j)
    c+=1

for i in range(x+1 , n+1):
    if c%2 == 0:
        for j in range(1 , m+1):
            print(i , j)
    else:
        for j in range(m , 0 , -1):
            print(i,j)
    c+=1
