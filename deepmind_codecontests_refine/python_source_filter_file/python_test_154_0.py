
t = int(input())
for i in range(t):
    lst = list(map(int, input().split()))
    m = max(lst)
    flag=-1
    if m == sum(lst)-m:
        flag=0
    else:
        lst1 = sorted(lst)
        for j in range(len(lst1) - 1):
            if lst1[j] == lst1[j + 1]:
                lst1.remove(lst1[j])
                lst1.remove(lst1[j])
                if lst1[0] % 2 == 0:
                    flag=0
                else:
                    flag=1
                break
            else:
                j = j + 1
    if flag==0:
        print("yes")
    elif flag==1:
        print("no")