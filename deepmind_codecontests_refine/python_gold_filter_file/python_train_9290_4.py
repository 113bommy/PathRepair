import math
n=int(input())


for i in range (n):
    a1,b1 = list(map(int, input().split()))
    a2,b2 = list(map(int, input().split()))
    area1 = a1 *a2
    area2 = b1 * b2
    totalarea = area1 + area2


    def Max(num1, num2):
        if num1 > num2:
            return num1
        else:
            return num2


    def Min(num1, num2):
        if num1 < num2:
            return num1
        else:
            return num2
    # print(area1)
    # print(area2)
    # print(totalarea)
    if (Max(a1,b1)==Max(a2,b2) and (Min(a1,b1)+Min(a2,b2)==Max(a1,b1))) :
        print("YES")
    else:
        print("NO")

