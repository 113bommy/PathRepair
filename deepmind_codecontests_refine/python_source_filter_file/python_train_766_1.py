n=int(input())
L=list(map(int,input().split()))
d={-1:[],0:[0],1:[]}
for i in range(len(L)):
    if L[i]<0:
        d[-1].append(L[i])
    elif L[i]>0:
        d[1].append(L[i])

if len(d[-1])%2!=0:
    if len(d[1])!=0:
        print(len(d[-1]),*d[-1])
        print(len(d[1]),*d[1])
        print("1 0")
    else:
        print(len(d[-1])-2,*d[-1][2:])
        print(2,*d[-1][:2])
        print("1 0")
else:
    if len(d[1])!=0:
        print(len(d[-1])-1,*d[-1][1:])
        d[0].append(d[-1][0])
        print(len(d[1]),*d[1])
        print(len(d[0]),*d[0])
    else:
        print(len(d[-1])-2,*d[-1][3:])
        d[0].append(d[-1][2])
        print(2,*d[-1][:2])
        print(len(d[0]),*d[0])
