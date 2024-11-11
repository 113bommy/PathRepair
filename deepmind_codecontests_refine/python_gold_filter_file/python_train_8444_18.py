y, b, r = list(map(int,input().split()))
for i in range(y,-1,-1):
    if i+1 in range(1,b+1) and i+2 in range(1,r+1):
        print(3*(i+1))
        break
