import math
n=int(input())
for i in range(n):
    x=int(input())
    for j in range(math.floor(x/7)+1):
        if (x-j*7)%3==0:
            print("YES")
            x=-1
            break
    if x%3==0 and x!=-1:
        print("YES")
    elif x!=-1:
        print("NO")