n= int(input())
l=[]
l.extend(map(int,input().split()))
f , e = (map(int,input().split()))
sum1=sum2=0
if e>f:
    max=e
    min=f
elif e<f:
    max=f
    min=e

if e==f:
    print(0)
else:

 for i in range(min,max):
    sum1+=l[i-1]

 for i in range(max-1,len(l),1):
    sum2+=l[i]

 if min-1>0:
        for j in range(0,min-1,1):
            sum2+=l[i]


 if sum1>sum2:
    print(sum2)
 else:
    print(sum1)