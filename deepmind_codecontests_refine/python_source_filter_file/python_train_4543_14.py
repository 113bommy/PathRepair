x,y,z = map(int, input().split())
if x-y %2 == 1 and z == -1:
    print(0)
else:
     print(pow(2,x*y-x-y+1,1000000007))