n = int(input())
for i in range(n):
    side = list(map(int,input().split()))

    side.sort()
    if(side[0]**2 + side[1]**2 == side[2]**2):
        print("Yes")
    else:
        print("No")