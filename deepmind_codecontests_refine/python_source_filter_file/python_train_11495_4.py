n = int(input())
a = [int(x) for x in input().split()]
dollars = [0,0] # 25, 50
ans = "YES"

for i in range(n):
    if a[i] == 25:
        dollars[0]+=1
    elif a[i] == 50:
        if dollars[0] == 0:
            ans="NO"
            break
        else:
            dollars[0]-=1
            dollars[1]+=1
    else:
        if (dollars[0] == 0 or dollars[1] == 0) and dollars[0]<2:
            ans="NO"
            break
        else:
            if dollars[1]>=1:
                dollars[0]-=1
                dollars[1]-=1
            else:
                dollars[0]-=2

print(ans)