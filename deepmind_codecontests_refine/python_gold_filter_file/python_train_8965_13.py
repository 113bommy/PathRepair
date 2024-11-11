a=[]
t=int(input())
for i in range(t):
    a+=[list(map(int,input().split()))]
for i in range(t):
    print(a[i][0],end=' ')
    if(a[i][0]!=a[i][2]):
        print(a[i][2])
    else:
        print(a[i][3])
