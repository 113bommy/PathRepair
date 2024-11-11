for _ in range(int(input())):
    l=list(map(int,input().split()))
    a=[0]*4
    if l[0]+l[3]!=0:l[0]=l[3]=1
    if l[1]+l[2]!=0:l[1]=l[2]=1
    if (l[0]+l[1])%2==0:a[0]=a[1]=0
    else:a[2]=a[3]=0
    for x in a:
        print(["Tidak","Ya"][x>0],end=' ')
    print('')