y,b,r=map(int,input().split())
for i in range(r,0,-1):
    if b>i-1 and y>=i-2:
        print(3*i-3)
        break


