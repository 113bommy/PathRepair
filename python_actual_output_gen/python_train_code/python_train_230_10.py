list1=list(map(int,input().split()))
sum1=sum(list1)
flag=0
if sum1%2==0:
    if sum1//2 in list1:
        flag=1
    for i in range(0,4):
        for j in range(i,4):
            if (list1[i]+list1[j])==sum1//2:
                flag=1
    if list1[0]+list1[1]+list1[2]==sum1//2:
        flag=1
    if list1[3]+list1[1]+list1[2]==sum1//2:
        flag=1
    if flag==1:
        print("YES")
    else:
        print("NO")
else:
    print("NO")