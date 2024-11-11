import math
t = int(input())
for tc in range(t):
    line = input().split()
    n, m = int(line[0]), int(line[1])
    
    count = 0
    flag = 0
    for i in range(n):
        line1 = input().split()
        line2 = input().split()
        x = int(line1[1])
        y = int(line2[0])
        a = int(line1[0])
        b = int(line2[1])
        if x == y:
            count += 1
        if x == y == a == b:
            flag = 1


    if m % 2 != 0:
        print("NO")
        continue


    if flag == 1:
        print("YES")
        continue
    else:
        if count >= 2:
            print("YES")
        else:
            print("NO")