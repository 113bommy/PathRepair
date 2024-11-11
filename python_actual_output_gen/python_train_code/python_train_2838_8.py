n=int(input())
data=[]
find=1
for i in range(n):
    s=[int(a) for a in input().split()]
    data.append(s)
datanew=sorted(data,key=lambda d:d[0])
st=datanew[0][1]
if len(datanew)==1:
    print('Happy Alex')
else:
    for x in range(1,len(datanew)):
        if datanew[x][1]>st:
            st=datanew[x][1]
        else:
            print('Happy Alex')
            find=0
            break
    if x==len(datanew)-1 and find==1:
        print('Poor Alex')
