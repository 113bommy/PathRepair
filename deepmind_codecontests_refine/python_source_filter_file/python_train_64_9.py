n=int(input())
x=[int(q) for q in input().split()]
mid=(1+10**6)//2
if max(x)<=mid:
    print(max(x)-1)
elif min(x)>=mid+1:
    print(10**6 - min(x))
else:
    a=0
    for i in range(n):
        if x[i]<mid:
            a=x[i]
    b=0
    y=x[::-1]
    for i in range(n):
        if y[i]>mid+1:
            b=y[i]
    print(max(a-1,10**6-b))