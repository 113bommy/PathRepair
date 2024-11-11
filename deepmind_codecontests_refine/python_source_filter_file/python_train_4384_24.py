h=list(map(int,input().split()))
num=0
for i in range(h[2]):
    num=(h[0]+h[1]-2)*2
    h[0]-=4
    h[1]-=4
print(num)
