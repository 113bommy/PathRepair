n=int(input())

l=[]

for i in range(n):
    l1=[int(x) for x in input().split()]
    l.append(l1)

cnt=0

for i in range(n):
    f1=0
    f2=0
    f3=0
    f4=0

    for j in range(1,n):
        if((l[j][0]==l[i][0]) and (l[j][1]>l[i][1])):
            f1=1
        elif((l[j][0]==l[i][0]) and (l[j][1]<l[i][1])):
            f2=1
        elif((l[j][0]>l[i][0]) and (l[j][1]==l[i][1])):
            f3=1
        elif((l[j][0]<l[i][0]) and (l[j][1]==l[i][1])):
            f4=1
    # print('f : ',f1,f2,f3,f4)
    if(f1==1 and f2==1 and f3==1 and f4==1):
        cnt+=1

print(cnt)
