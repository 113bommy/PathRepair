t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    if (a[0]>0):
        pos = a[0]
        flag=True
        ans_sum = a[0]
    elif (a[0]<0):
        neg = a[0]
        flag=False
        ans_sum = a[0]
    for j in range(1,n):
        if ((a[j]>0)):
            if ((flag==True)):
                if ((a[j]>pos)):
                    ans_sum = ans_sum - pos
                    pos = a[j]
                    ans_sum = ans_sum + a[j]
            else:
                pos = a[j]
                ans_sum = ans_sum + a[j]
                flag=False
        else:
            if ((flag==False)):
                if ((a[j]>neg)):
                    ans_sum = ans_sum - neg
                    neg = a[j]
                    ans_sum = ans_sum + a[j]
            else:
                neg = a[j]
                ans_sum = ans_sum + a[j]
                flag=False
    print(ans_sum)





