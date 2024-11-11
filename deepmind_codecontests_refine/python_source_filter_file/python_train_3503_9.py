x=[]
for i in range(4):
    x.append(int(input()))
n=x[0]
k=x[1]
a=x[2]
b=x[3]
cost=0
x=n

while int(x)!=1:
    if k==1:
        cost=cost+((x-1)*a)
        x=1
    elif x<k:
        cost=cost+((x-1)*a)
        x=1
    elif x==k:
        if b>(x-1)*a:
            cost=cost+(x-1)*a
            x=1
        else:
            cost=cost+b
            x=1
    elif x>k:
        re=x%k
        if re > 0 :
            cost=re*a
            x=x-re
        else:
            if b<(x-(x/k))*a:
                cost=cost+b
                x=int(x/k)
            else:
                cost=cost+(x-(x/k))*a
                x=int(x/k)
print(int(cost))

