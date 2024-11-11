n = int(input())
aq = list(map(int, input().split()))
bk = list(map(int, input().split()))
lk = list(map(int, input().split()))
if (bk[0] < aq[0]) and (lk[0] < aq[0]):
    if ((bk[1] < aq[1] and lk[1] < aq[1]) or (bk[1] > aq[1] and lk[1] > aq[1])):
        print("YES")
    else:
        print("NO")
elif (bk[0] > aq[0]) and (lk[0] > aq[0]):
    if ((bk[1] > aq[1] and lk[1] > aq[1]) or (bk[1] < aq[1] and lk[1] < aq[1])):
        print("YES")
    else:
        print("NO")
else:
    print("NO")
