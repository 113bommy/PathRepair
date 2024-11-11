

n,m = map(int,input().split())

list1 = []
for i in range(n):
    temp = list(map(int,input().split()))
    list1.append(temp)


temp = 0
ans = [1 for i in range(n)]
for i in range(n):
    temp = temp^list1[i][0]
if temp>0:
    print("TAK")
    print(*ans)
else:
    f=0
    for i in range(n):
        for j in range(1,m):
            if list1[i][j]!=list1[0][j]:
                ans[i] = j+1
                f=1
                break
        if f==1:
            break
    if f==0:
        print("NIL")
    else:
        print("TAK")
        print(*ans)
