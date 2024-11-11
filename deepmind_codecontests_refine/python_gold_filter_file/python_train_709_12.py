N=int(input())
a=list(map(int,input().split()))
l=[0]*N
for i in range(N):
    if a[i]%4:
        if a[i]%2:l[i]=1
        else:l[i]=2
    else:l[i]=4
print('Yes'if l.count(1)+(1 if l.count(2)else 0)<=1+l.count(4)else'No')