s = str(input())
c0 = 0
c1 = 0
for i in s:
    if i=='0' and c0%2==0:
        print(3,1)
        c0+=1
    elif i=='0' and c0%2==1:
        print(1,1)
        c0+=1
    if i=='1' and c1%2==0:
        print(1,3)
        c1+=1
    elif i=='1' and c1%2==1:
        print(1,1)
        c1+=1