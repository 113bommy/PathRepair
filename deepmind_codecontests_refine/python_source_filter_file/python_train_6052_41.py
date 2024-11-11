s = input()
r=0
c=0
for i in s:
    if i=='0' and r==0:
        print(1,1)
        r=1
    elif i=='0' and r==1:
        print(1,3)
        r=0
    elif i=='1' and c==0:
        print(4,3)
        c=1
    else:
        print(4,1)
        c=0