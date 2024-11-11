n=int(input())
for i in range(n):
    x,y,z=list( map(int,input().split()))
    print(int(max(0,z-max((y+z-x+2)/2,0)+1)))
