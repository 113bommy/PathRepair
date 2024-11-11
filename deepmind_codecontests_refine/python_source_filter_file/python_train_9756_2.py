n=int(input())
i1={}
i2={}
sum=0
for i in range(n):
    l,k=map(int,input().split())
    i1[l]=k
m=int(input())
for j in range(m):
    l,k=map(int,input().split())
    i2[l]=k
for key in i1 :
    if key in i2 :
        if i1[key]>i2[key]:
            sum +=i1[key]
        else :
            sum +=i2[key]
        i2[key]=0
        i1[key]=0
    else :
        sum +=i1[key]
for key2 in i2 :
    sum += i2[key]
print (sum)