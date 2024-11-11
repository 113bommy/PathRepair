 
n = int(input())
print((n-1)*3 + 7)
print(0,0)
print(0,-1)
print(1,0)
print(1,-1)
xy = [1,-1]
for i in range(n):
    print(xy[0]+1,xy[0])
    print(xy[0],xy[1]-1)
    xy[0] += 1
    xy[1] -= 1
    print(xy[0],xy[1])
