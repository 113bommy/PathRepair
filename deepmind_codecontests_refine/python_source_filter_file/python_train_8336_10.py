n=int(input())
d={}
a=list(map(int,input().split()))
for i in a:
    d[i]=d.get(i,0)+1
p=[2**i for i in range(18)]

count=0
for i in range(len(a)):
    t=True
    for j in p:
        dif=j-a[i]
        if dif in d:
            if dif!=a[i]:
                t=False
            elif d[a[i]]>1:
                t=False
    if t==True:
        count+=1
print(count)
