n, m, x, y = map(int, input().split())
print(x,y)
print(1,y)
f1,f2 = x, y
for x in range(1,n+1):
    if x % 2 !=0:
        for y in range(1,m+1):
            if [x,y] != [f1,f2] and [x,y] != [1,f2]:
                print(x,y)
    else:
        for y in range(m,0,-1):
            if [x,y] != [f1,f2] and [x,y] != [1,f2]:
                print(x,y)