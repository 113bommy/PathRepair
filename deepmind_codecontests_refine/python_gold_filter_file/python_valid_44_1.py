c = int(input())
# print(c)
for i in range(c):
    # print(i)
    strs = input().split(' ')
    a = int(strs[0])
    b = int(strs[1])
    # print(a, b)
    if a == b:
        if a == 0:
            print(0)
        else:
            print(1)
    elif (a -  b) % 2 == 0:
        print(2)
    else:
        print(-1)