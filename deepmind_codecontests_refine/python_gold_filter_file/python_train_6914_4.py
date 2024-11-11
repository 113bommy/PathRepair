n = int(input())
a = list(map(int, input().split()))
r = ' '
move_right = True

while 1:
    if move_right:
        for i in range(n):
            if a[i]>0 and r[-1]!="P":
                r+="P"
                a[i]-=1
            if i!=n-1:
                r+="R"
        move_right = not move_right
        # print(a, r)
    else:
        for i in range(n-1,-1,-1):
            if a[i]>0 and r[-1]!="P":
                r+="P"
                a[i]-=1
            if i!=0:
                r+="L"
        move_right = not move_right
        # print(a, r)
    if sum(a) == 0:
        break

print(r[1:])
