hand = list(input())
l = list(input().split())
for i in range(0,5) :
    list(l[i])
flag1 = 0
flag2 = 0
for i in range(0,5) :
    if hand[0] == l[i][0] :
        flag1 = 1
if flag1 == 0 :
    for i in range(0,4) :
        if hand[1] == l[i][1] :
            flag2 = 1
if flag1 or flag2 :
    print("YES")
else :
    print("NO")