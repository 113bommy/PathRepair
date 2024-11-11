n=int(input())
ab=[]
for i in range(n):
    ab.append([int(x) for x in input().split()])
ab.sort(key=lambda x:(x[0],x[1]))
md=0
asw=0
for i in range(n):
    if i!=0 and asw==0:
        if ab[i][1]<ab[i-1][1]:
            asw=1
            md=ab[i][0]
        else:
            md=ab[i][1]
        continue
    elif i!=0 and asw==1:
        if ab[i][1]>ab[i-1][0]:
            asw=0
            md=ab[i][1]
        else:
            md=ab[i][0]
        continue
    else:
        md=ab[i][1]
print(md)
