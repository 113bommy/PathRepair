n = int(input())
a= []
flag=0
while(n>3):
    if n%7==0:
        for i in range(n//7):
            a.append(7)
        flag = 1
        n = 0
    else:
        n-=4
        a.append(4)
        if n==0:
            flag=1
if flag==1:
    for i in a:
        print(i,end='')
else:
    print(-1)
        