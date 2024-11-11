n = int(input())
a = [int(x) for x in input().split()]
cnt_1 = a.count(1)
cnt_2 = a.count(2)
if cnt_1 == 0:
    print(0)
elif cnt_2 == 0:
    print(sum(a)//3)
else:
    if cnt_1<=cnt_2:
        print(cnt_1)
    else:
        print(cnt_2+(cnt_1-cnt_2)//3)