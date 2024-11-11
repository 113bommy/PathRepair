
n,m=map(int,input().split())
a=[]
f=0
ind=-1
for i in range(n):
    a.append(list(map(int,input().split())))
    k=len(set(a[-1]))
    if k>1:
        f=1
        ind=i
        # break
if ind==-1:
    xor=0
    for i in range(n):
        xor^=a[i][0]
    if xor==0:
        print("NIE")
    else:
        print("TAK")
        print('1 '*n)
else:
    for i in range(m-1):
        if a[ind][i]!=a[ind][i+1]:
            x=i
            y=i+1
            break
    print("TAK")
    xor=0
    for i in range(n):
        # print(i,x)
        if i!=ind:
            xor^=a[i][0]
        else:
            xor^=a[i][x]
    if xor==0:
        for i in range(n):
            if i!=ind:
                xor^=a[i][0]
            else:
                xor^=a[i][y]
        print("1 "*ind + (str(y+1)+' ') + '1 '*(n-ind-1))
    else:
        print("1 "*ind + (str(x+1)+' ') + '1 '*(n-ind-1))
        


        
        