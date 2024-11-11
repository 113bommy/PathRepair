m = int(input())
for i in range(m):
    x = int(input())
    if(360%(180-x)!=0):
        print("NO")
    else:
        print("YES")
