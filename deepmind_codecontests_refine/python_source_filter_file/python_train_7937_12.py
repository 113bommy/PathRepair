t=int(input())
while t>0:
    size=int(input())
    inp=list(map(int, input().split()))
    start=[]
    end=[]
    flag=0
    for i in range(size):
        if flag==0 and inp[i]!=i+1:
            start.append(i+1)
            flag=1
        elif flag==1 and inp[i]==i+1:
            end.append(i)
            flag=0
    temp=int(len(start))
    if temp<2:
        print(temp)
    else:
        print(temp)
    t-=1