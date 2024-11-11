n=int(input())
a=[];b=[];c=[1]*n
for _ in range(n):
    x,y=map(int,input().split())
    a.append(x)
    b.append(y)
for i in range(n):
    for j in range(n):
        if a[i]==b[j] and i!=j:
            c[j]=0;
# print(c)
print(sum(c))