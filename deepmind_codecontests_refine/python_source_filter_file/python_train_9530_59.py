n = int(input())
x = 2400
flag = False
while n > 0:
    n -= 1
    a = [i for i in input().split()]
    # print(a)

    if int(a[1]) >= x and int(a[2]) > x:
        flag = True
        break
    else:
        flag=False

if flag == True:
    print("YES")
else:
    print("NO")
